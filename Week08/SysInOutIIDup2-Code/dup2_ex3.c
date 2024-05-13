#include <stdio.h>
#include <err.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sysexits.h>

#define NAME_LENGTH 8

void print_evens() {
   int limit, i;

   printf("Enter limit: ");
   scanf("%d", &limit);

   for (i = 2; i <= limit; i += 2) {
      printf("%d\n", i); 
   }
}

int main(int argc, char **argv) { /* Command line argument */
   const char *datafile = "limit.txt";
   int fd;

   if ((fd = open(datafile, O_RDONLY)) < 0) {
      err(EX_OSERR, "File opening failed");
   } 

   if (dup2(fd, STDIN_FILENO) < 0) { /* Now stdin is associated with file */
      err(EX_OSERR, "dup2 (read) failed");
   }
       
   /* When scanf reads data it will now read data from the file */
   print_evens();

   if (close(fd) < 0) { /* We need it otherwise resource leak */
     err(EX_OSERR, "close error");
   }

   exit(0);
}
