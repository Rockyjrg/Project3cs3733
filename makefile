# Makefile for FIFO Page Replacement project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Target executable
TARGET = memory_manager

# Source files
SRC = FIFO.c

# Input file
INPUT = inputFIFO.txt

# Default rule
all: $(TARGET)

# Rule to compile the program
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Rule to run the program with input
run: $(TARGET)
	./$(TARGET) < $(INPUT)

# Clean rule to delete compiled files
clean:
	rm -f $(TARGET)
