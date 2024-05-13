/* 
 * Input/output redirection example
 *
 * Try 1: dup2Ex1  
 *        Enter a string with 8 characters (e.g., "Maryland")    
 *
 * Try 2: dup2Ex1 data.txt
 *        In file data.txt you need to have 8 characters
 *
 */

#include <stdio.h>
#include <err.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sysexits.h>

#define NAME_LENGTH 8

int main(int argc, char **argv) { /* Using command line arguments */
   char buffer[NAME_LENGTH]; /* Not including null character */
   int fd;

   if (argc > 1) { /* If given a filename we will open it */
      if ((fd = open(argv[1], O_RDONLY)) < 0) {
         err(EX_OSERR, "File opening failed.\n");
      } 
      if (dup2(fd, STDIN_FILENO) < 0) { /* stdin now associated with the file */
         err(EX_OSERR, "dup2 error");
      }
      if (close(fd) < 0) { /* We need it otherwise resource leak */
         err(EX_OSERR, "close error");
      }
   }     

   /* If dup2 did not take place, input will come from the keyboard. */
   /*  Otherwise, input will come from the specified file   */
   read(STDIN_FILENO, buffer, NAME_LENGTH);  

   /* Writing to the terminal the data read */
   write(STDOUT_FILENO, buffer, NAME_LENGTH);

   exit(0);
}
