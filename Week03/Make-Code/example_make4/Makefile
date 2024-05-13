CC = gcc
CFLAGS =  -ansi -Wall -g -O0 -Wwrite-strings -Wshadow -pedantic-errors -fstack-protector-all 

#notice no linking command
breakfast: breakfast.o bread.o coffee.o

breakfast.o: breakfast.c bread.h coffee.h
bread.o: bread.c bread.h
coffee.o: coffee.c coffee.h

.PHONY: clean

clean:
	@echo "Cleaning my system"
	@rm -f *.o breakfast a.out

