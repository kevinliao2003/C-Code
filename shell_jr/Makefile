# provide a makefile with a target called shell_jr that 
# creates the executable shell_jr
shell_jr: shell_jr.o
	gcc shell_jr.o -o shell_jr

shell_jr.o: shell_jr.c
	gcc -c shell_jr.c

clean:
	@echo "Removing object, executable, and core files."
	rm -f *.o *~ core core.