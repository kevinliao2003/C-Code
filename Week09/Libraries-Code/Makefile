CC = gcc
CFLAGS =  -ansi -Wall -g -O0 -Wwrite-strings -Wshadow -fstack-protector-all

EXECUTABLES = example_for_ldd dyn_load_math_lib

all: $(EXECUTABLES) 

example_for_ldd: example_for_ldd.o 
	$(CC) -o $@ example_for_ldd.o -lm

dyn_load_math_lib: dyn_load_math_lib.o
	$(CC) -rdynamic -ldl dyn_load_math_lib.o -o $@

clean:
	rm -f $(EXECUTABLES) *.o a.out *.c~  *.h~
