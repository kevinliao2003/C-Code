# 1. Comment: A comment starts with # and extends until end of the line
# 2. A macro is a makefile variable
# 3. We can continue on the next line using \
# 4. Sometimes not leaving a blank line at the end of the file can cause problems
# 5. We can name the file Makefile or makefile
# 6. Do not use CFLAGS during the linking process (see breakfast target below)
# 7. While developing your code, make a copy of your code before running make clean.
#    If you have a run clean target you could remove your code by mistake.

CC = gcc
CFLAGS =  -ansi -Wall -g -O0 -Wwrite-strings -Wshadow -pedantic-errors \
-fstack-protector-all 
LDFLAGS = -lm

.PHONY: clean all

# Our programs (executables)
PROGS = breakfast

# First target
all: $(PROGS)

breakfast: breakfast.o bread.o coffee.o
	$(CC) -o breakfast breakfast.o bread.o coffee.o $(LDFLAGS)

breakfast.o: breakfast.c bread.h coffee.h
	$(CC) $(CFLAGS) -c breakfast.c

bread.o: bread.c bread.h
	$(CC) $(CFLAGS) -c bread.c

coffee.o: coffee.c coffee.h
	$(CC) $(CFLAGS) -c coffee.c

clean:
	@echo "Cleaning my system"
	@rm -f *.o $(PROGS) a.out

