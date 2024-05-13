
CC = gcc
CFLAGS =  -ansi -Wall -g -O0 -Wwrite-strings -Wshadow -pedantic-errors \
-fstack-protector-all 
LDFLAGS = -lm

.PHONY: clean all

# Our programs (executables)
PROGS = linked_list wrong_list_insertion  

all: $(PROGS) 

clean:
	@echo "Cleaning my system"
	@rm -f *.o $(PROGS) a.out

