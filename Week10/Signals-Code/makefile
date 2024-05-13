CC = gcc
CFLAGS = -ansi -Wall -g -O0 -Wwrite-strings -Wshadow -fstack-protector-all 
PROGS = alarm_ex1 alarm_ex2 catching_ctrl_c_ex terminate_child_ex1 \
	terminate_child_ex2 start_stop_child

all: $(PROGS)

clean:
	@rm -f *.o $(PROGS) a.out *.c~ *.h~
