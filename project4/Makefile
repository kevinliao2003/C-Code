CC = gcc
CFLAGS = -ansi -Wall -g -O0 -Wwrite-strings -Wshadow \
         -pedantic-errors -fstack-protector-all
PROGS = public01 public02 public03 public04 public05 \
	public06 student_tests

.PHONY: all clean

all: $(PROGS)

# my_memory_checker_216 only necessary for executable
# event only needed for source code
# o indicates source code
public01: public01.o calendar.o my_memory_checker_216.o
	gcc -o public01 public01.o calendar.o my_memory_checker_216.o

public01.o: public01.c event.h calendar.h
	$(CC) $(CFLAGS) -c public01.c

public02: public02.o calendar.o my_memory_checker_216.o
	gcc -o public02 public02.o calendar.o my_memory_checker_216.o

public02.o: public02.c event.h calendar.h
	$(CC) $(CFLAGS) -c public02.c

public03: public03.o calendar.o my_memory_checker_216.o
	gcc -o public03 public03.o calendar.o my_memory_checker_216.o

public03.o: public03.c event.h calendar.h
	$(CC) $(CFLAGS) -c public03.c

public04: public04.o calendar.o my_memory_checker_216.o
	gcc -o public04 public04.o calendar.o my_memory_checker_216.o

public04.o: public04.c event.h calendar.h
	$(CC) $(CFLAGS) -c public04.c

public05: public05.o calendar.o my_memory_checker_216.o
	gcc -o public05 public05.o calendar.o my_memory_checker_216.o

public05.o: public05.c event.h calendar.h
	$(CC) $(CFLAGS) -c public05.c

public06: public06.o calendar.o my_memory_checker_216.o
	gcc -o public06 public06.o calendar.o my_memory_checker_216.o

public06.o: public06.c event.h calendar.h
	$(CC) $(CFLAGS) -c public06.c

# source code must be compiled for student_tests, calendar, 
# and my_memory_checker_216
# -o must be present for source code
student_tests: student_tests.o calendar.o my_memory_checker_216.o
	gcc -o student_tests student_tests.o calendar.o my_memory_checker_216.o

student_tests.o: student_tests.c event.h calendar.h
	$(CC) $(CFLAGS) -c student_tests.c -o student_tests.o

calendar.o: calendar.c calendar.h
	$(CC) $(CFLAGS) -c calendar.c -o calendar.o

my_memory_checker_216.o: my_memory_checker_216.c my_memory_checker_216.h
	$(CC) $(CFLAGS) -c my_memory_checker_216.c -o my_memory_checker_216.o

clean:
	@echo "Removing object, executable, and core files."
	rm -f *.o *~ core core.*