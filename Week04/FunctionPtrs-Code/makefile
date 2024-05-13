
CC = gcc
CFLAGS =  -ansi -Wall -g -O0 -Wwrite-strings -Wshadow -pedantic-errors \
-fstack-protector-all 
LDFLAGS = -lm

.PHONY: clean all

# Our programs (executables)
PROGS = basics_function_ptrs1 basics_function_ptrs2 multiplication_table \
ptr_to_ptr_variable free_function sort_array 

all: $(PROGS) 

clean:
	@echo "Cleaning my system"
	@rm -f *.o $(PROGS) a.out

