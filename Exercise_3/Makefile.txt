# Compiler
Comp = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Wfatal-errors -Wpedantic

# List of source files
SRC = main.c random_generator.c error_handling.c

# Object files (replace .c with .o)
OBJ = $(SRC:.c=.o)

# Final executable
TARGET = random_generator

# Default target: build the executable
$(TARGET): $(OBJ)
	$(Comp) $(CFLAGS) -o $@ $^ # Link object files to create the executable

# Rule to compile each .c file into .o file
%.o: %.c random_generator.h error_handling.h
	$(Comp) $(CFLAGS) -c $<

# Clean rule to remove object and executable files
.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)

# Comments:
# - Comp is the compiler.
# - CFLAGS holds all the compiler flags.
# - SRC is the list of source files.
# - OBJ automatically converts .c files into .o files.
# - $@ represents the target (random_generator), and $^ represents all dependencies.
# - %.o: %.c is a pattern rule to compile .c into .o files.
