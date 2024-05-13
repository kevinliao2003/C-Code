CC = gcc
CFLAGS = -ansi -Wall -g -O0 -Wwrite-strings -Wshadow -pedantic-errors -fstack-protector-all 
PROGS = clock_ex sleeper time_functions time_usage

all: $(PROGS)

clean:
	@echo "Cleaning executables and .o files" 
	@rm -f *.o $(PROGS) a.out temp_file_remove_it.txt *.c~ *.h~
