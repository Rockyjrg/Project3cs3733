#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 50

typedef struct
{
    int pages_num;
    int curr;
    int pages[MAXLEN];
    int faults;
    int used[MAXLEN];

} memory;

memory *memory_init(int n)
{
    // create a new memory struct
    // initializing its parameters
    memory *m;
    m = malloc(sizeof(memory));
    m->pages_num = n;
    m->curr = 0;
    m->faults = 0;
    for (int i = 0; i < MAXLEN; i++)
    {
        m->pages[i] = 0;
        m->used[i] = 0;
    }
    return m;
}

int search_process(memory *m, int process)
{
    // search if the process exists in the memory
    int num = m->pages_num;
    for (int i = 0; i < num; i++)
    {
        if (m->pages[i] == process)
            return i;
    }
    return -1;
}

void display_pages(memory *m)
{
    // print all memory pages to console
    int num = m->pages_num;
    for (int i = 0; i < num; i++)
    {
        if (m->used[i])
            printf("%02d ", m->pages[i]);
    }
}

void add_process(memory *m, int process)
{
    // check if the process is already in the memory
    if (search_process(m, process) >= 0)
    {
        printf("%02d    ", process);
        display_pages(m);
        printf("\n");
        return;
    }
    // add the process to memory and
    // update the pointer for next page
    m->pages[m->curr] = process;
    if (m->used[m->curr] == 1)
    {
        m->faults++;
        printf("%02d F  ", process);
        display_pages(m);
        printf("\n");
        m->curr = (m->curr + 1) % m->pages_num;
        return;
    }
    m->used[m->curr] = 1;
    m->curr = (m->curr + 1) % m->pages_num;
    printf("%02d    ", process);
    display_pages(m);
    printf("\n");
}

int memory_FIFO(int num)
{
    memory *m = memory_init(num);
    int input;
    printf("----------------------------------------------------\n");
    printf("Page    Content of Frames\n");
    printf("----    -----------------\n");
    while (1)
    {
        scanf("%d", &input);
        if (input == -1)
            break;
        add_process(m, input);
    }
    printf("------------------------------------------------------\n");
    printf("Number of page faults = %d\n", m->faults);
}

int main()
{
    int num;
    char algo[6];

    scanf("%d", &num);
    scanf("%s", algo);
    printf("Replacement Policy = %s\n", algo);

    if (strcmp(algo, "FIFO") == 0)
        memory_FIFO(num);
}