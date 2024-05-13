
CC = gcc
CFLAGS =  -ansi -Wall -g -O0 -Wwrite-strings -Wshadow -pedantic-errors \
-fstack-protector-all 
LDFLAGS = -lm

.PHONY: clean all

# Our programs (executables)
PROGS = bitwise_op_byte endian_type printing bitwise_op flip_clear_nibbles \
shifting

all: $(PROGS) 

clean:
	@echo "Cleaning my system"
	@rm -f *.o $(PROGS) a.out

