CC = gcc

CFLAGS= -ansi -Wall -g -O0 -Wwrite-strings -Wshadow -pedantic-errors -fstack-protector-all
LDFLAGS = -lm
PROGS = pipe_int sandwich pipe_powers table pipe_exec 

all: $(PROGS)

clean: 
	rm -f a.out *.o $(PROGS) results.txt *.c~ 
