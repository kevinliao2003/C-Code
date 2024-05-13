CC = gcc
CFLAGS =  -ansi -Wall -g -O0 -Wwrite-strings -Wshadow -pedantic-errors -fstack-protector-all
LIBRARY_TO_CREATE = libMyArchive.a
# Object files that will be part of the library
OBJS = first.o second.o


all: $(LIBRARY_TO_CREATE) main main_no_lib

main: main.o $(LIBRARY_TO_CREATE)
	$(CC) -o $@ main.o $(LIBRARY_TO_CREATE) 

# Alternative to above target (notice the -L. and -lMyArchive)
# main: main.o $(LIBRARY_TO_CREATE)
#	$(CC) -o $@ main.o -L. -lMyArchive 

$(LIBRARY_TO_CREATE): $(OBJS)
	ar cru $(LIBRARY_TO_CREATE) $(OBJS)

# main without library
main_no_lib: first.o second.o main.o
	$(CC) -o $@ first.o second.o main.o

clean:
	rm -f $(OBJS) main.o main main_no_lib $(LIBRARY_TO_CREATE) *.c~  *.h~
