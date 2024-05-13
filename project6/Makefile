CC = gcc
CFLAGS = -ansi -Wall -g -O0 -Wwrite-strings -Wshadow \
         -pedantic-errors -fstack-protector-all 
PROGS = d8sh

.PHONY: all clean

all: $(PROGS)

lexer.o: lexer.c lexer.h parser.tab.h
parser.tab.o: parser.tab.c parser.tab.h command.h
executor.o: executor.c executor.h command.h
d8sh.o: d8sh.c lexer.h executor.h

d8sh: lexer.o parser.tab.o executor.o d8sh.o
	$(CC) -o d8sh lexer.o parser.tab.o executor.o d8sh.o -lreadline

clean:
	@echo "Removing object, executable, and core files."
	rm -f *.o d8sh