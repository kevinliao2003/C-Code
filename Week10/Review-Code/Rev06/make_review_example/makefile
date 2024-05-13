# Comment: A comment starts with # and extends until end of the line
# Macros:
# A macro is a makefile variable
# We can continue on the next line using \
# Sometimes not leaving a blank line at the end of the file can cause problems
# We can name the file Makefile or makefile
# Important: do not use CFLAGS in linking process (see breakfast target below)

CC = gcc
CFLAGS =  -ansi -Wall -g -O0 -Wwrite-strings -Wshadow -pedantic-errors \
-fstack-protector-all 

.PHONY: clean all

# Our programs (executables)
PROGS = breakfast

all: $(PROGS)

breakfast: breakfast.o bread.o coffee.o
	$(CC) -o breakfast breakfast.o bread.o coffee.o

breakfast.o: breakfast.c bread.h coffee.h
	$(CC) $(CFLAGS) -c breakfast.c

bread.o: bread.c bread.h
	$(CC) $(CFLAGS) -c bread.c

coffee.o: coffee.c coffee.h
	$(CC) $(CFLAGS) -c coffee.c

clean:
	@echo "Cleaning my system"
	@rm -f *.o $(PROGS) a.out

