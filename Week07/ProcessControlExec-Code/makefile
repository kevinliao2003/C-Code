CC = gcc

CFLAGS= -ansi -Wall -g -O0 -Wwrite-strings -Wshadow -fstack-protector-all -pedantic-errors 
PROGS = evens exec_evens exec_evens_arg execve1 execle2 execlp3 execvp4 \
        sleeper reaping_for_shell wait_reap_deterministic wait_reap_non_deterministic  

all: $(PROGS)

clean: 
	rm -f a.out *.o $(PROGS)
