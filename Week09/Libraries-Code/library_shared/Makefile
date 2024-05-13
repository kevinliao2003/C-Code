CC = gcc
CFLAGS =  -ansi -Wall -g -O0 -Wwrite-strings -Wshadow -fstack-protector-all -fPIC

# Flags for the shared library creation
LIBFLAGS = -nostdlib -shared -fPIC -Wl,-soname,$@.1

all: libMySharedLib.so main

# Creating shared library
libMySharedLib.so: first.o second.o
	$(CC) $(LIBFLAGS) first.o second.o -o libMySharedLib.so.1
	# Creating symbolic link (allows library update)
	ln -s -f libMySharedLib.so.1 libMySharedLib.so

# main using the shared library (look at the name specification)
main: main.o libMySharedLib.so  
	$(CC) -o $@ main.o -L. -lMySharedLib
	@echo ""
	@echo "Make sure you have set LD_LIBRARY_PATH to current directory"
	@echo ""

clean:
	rm -f *.o main lib* *.c~ *.h~
