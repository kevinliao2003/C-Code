# Comment: A comment starts with # and extends until end of the line

# Macros:
# A macro is a makefile variable
# To define it we just use the name = value.  Notice
# that to use its value we need $ ( For example, $(CC) )
#

CC = gcc
CFLAGS =  -ansi -Wall -g -O0 -Wwrite-strings -Wshadow -pedantic-errors \
-fstack-protector-all 

# Our programs (executables)
PROGS = breakfast

all: $(PROGS)

# Important: do not use CFLAGS in linking process (see breakfast below)
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

