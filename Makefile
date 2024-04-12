# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11 -Wall

# Source directories
SRCDIRS = vector list deque

# Object directories
OBJDIRS = $(SRCDIRS:%=%/obj)

# Executable names
EXEC = v l d

# Text file name
TXTFILES = studentai1000.txt studentai10000.txt studentai100000.txt studentai1000000.txt studentai10000000.txt

# Default target
all: $(EXEC)

# Build targets for each version of the program
v: vector/1.0main.o vector/isFailo.o vector/rusiavimasGen.o vector/papFunkcijos.o vector/failuGen.o 
	$(CC) $(CFLAGS) $^ -o $@

l: list/1.0main.o list/isFailo.o list/rusiavimasGen.o list/papFunkcijos.o list/failuGen.o
	$(CC) $(CFLAGS) $^ -o $@

d: deque/1.0main.o deque/isFailo.o deque/rusiavimasGen.o deque/papFunkcijos.o deque/failuGen.o
	$(CC) $(CFLAGS) $^ -o $@

# Build rule for object files in each directory
%/obj/%.o: %/%.cpp %/funkcijos.h %/student.h
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to copy the text file to the current directory
$(TXTFILES):
	cp $@ $(foreach exec,$(EXEC),$(dir $(exec)))

# Clean command
clean:
	rm -f $(foreach dir,$(OBJDIRS),$(wildcard $(dir)/*.o))
	rm -f $(EXEC)
