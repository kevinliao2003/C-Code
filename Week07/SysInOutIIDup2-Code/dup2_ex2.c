/*
 * Input/output redirection example
 *
 * Try 1: dup2Ex2
 *        Enter a string with 8 characters (e.g., "Maryland")
 *
 * Try 2: dup2Ex2 data.txt
 *        In data.txt file you need to have a character with 8 characters
 *
 * Try 3: dup2Ex2 data.txt output.txt
 *        The output.txt file will be overwritten with contents of data.txt
 */

#include <stdio.h>
#include <err.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sysexits.h>

#define NAME_LENGTH 8

#define FILE_PERMISSIONS 0666

int main(int argc, char **argv) { /* Command line argument */
   char buffer[NAME_LENGTH]; /* Not including null character */
   int fd;

   if (argc > 1) {
      /* If we have a second argument that represents the input file */
      if ((fd = open(argv[1], O_RDONLY)) < 0) {
         err(EX_OSERR, "File opening (read) failed");
      } 

      if (dup2(fd, STDIN_FILENO) < 0) { /* Now stdin is associated with file */
         err(EX_OSERR, "dup2 (read) failed");
      }
       
      if (close(fd) < 0) { /* We need it otherwise resource leak */
         err(EX_OSERR, "close error");
      }

      /* If we have a third argument that represents the output file */
      if (argc == 3) {
         if ((fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMISSIONS)) < 0) {
            err(EX_OSERR, "File opening (write) failed");
         }

         if (dup2(fd, STDOUT_FILENO) < 0) { /* Now stdout is associated with file */
            err(EX_OSERR, "dup2 (write) failed");
         } 

         if (close(fd) < 0) { /* We need it otherwise resource leak */
            err(EX_OSERR, "close error");
         }
      }
   }     

   /* Reading from stdin if no input file;  */
   /* provided; otherwise reading from file */
   read(STDIN_FILENO, buffer, NAME_LENGTH);

   /* Writing to stdout if no output file;  */
   /* provided; otherwise writing to file   */
   write(STDOUT_FILENO, buffer, NAME_LENGTH);
   
   exit(0);
}
