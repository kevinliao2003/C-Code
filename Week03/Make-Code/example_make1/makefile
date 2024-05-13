breakfast: breakfast.o bread.o coffee.o
	gcc -o breakfast breakfast.o bread.o coffee.o

breakfast.o: breakfast.c bread.h coffee.h
	gcc -c breakfast.c

bread.o: bread.c bread.h
	gcc -c bread.c

coffee.o: coffee.c coffee.h
	gcc -c coffee.c

all: clean breakfast

clean:
	@echo "Cleaning my system"
	@rm -f *.o breakfast a.out

