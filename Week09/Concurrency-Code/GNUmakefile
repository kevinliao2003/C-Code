CC = gcc
CFLAGS = -ansi -Wall -g -O0 -Wwrite-strings -Wshadow -pedantic-errors -fstack-protector-all 
LDFLAGS = -lpthread
PROGS = threads_basics threads_ret_sqr_value threads_several threads_sync threads_no_sync


all: $(PROGS)

clean:
	@echo "Cleaning executables and .o files"
	@rm -f *.o $(PROGS) a.out
