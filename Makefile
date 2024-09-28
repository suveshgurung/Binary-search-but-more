# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11

# Sources for each program
SORT_SRC = selectionSorting.c
SEARCH_SRC = binarySearch.c

# Object files for each program
SORT_OBJS = $(SORT_SRC:.c=.o)
SEARCH_OBJS = $(SEARCH_SRC:.c=.o)

# Targets
SORT = sort
SEARCH = binarySearch 

# Default target
all: $(SORT) $(SEARCH)

# Rule for sort 
$(SORT): $(SORT_OBJS)
	$(CC) $(CFLAGS) -o $(SORT) $(SORT_OBJS)

# Rule for search 
$(SEARCH): $(SEARCH_OBJS)
	$(CC) $(CFLAGS) -o $(SEARCH) $(SEARCH_OBJS)

# Rule to compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -rf $(SORT) $(SEARCH) $(SORT_OBJS) $(SEARCH_OBJS)
