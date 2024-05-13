/*
  Illustrates the file descriptors associated
  with standard input (0), standard output (1).
  Remember standard error is (2).  To run the 
  example, enter a string with a length of at
  least 5 characters. Also the example illustrates
  we can print characters to the screen, but to
  print integers we will need standard I/O.
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define LENGTH 5
#define BYE_MESSAGE_LENGTH 4

int main() {
   char buffer[LENGTH];
   unsigned int x = 123456;

   /* Use STDIN_FILENO instead of 0 */ 
   read(0, buffer, LENGTH); /* Enter string with at least 5 characters */

   /* Use STDOUT_FILENO instead of 1 */
   write(1, buffer, LENGTH);

   write(STDOUT_FILENO, "Bye\n", BYE_MESSAGE_LENGTH);

   write(1, &x, sizeof(unsigned int)); /* We will not see the number.  Why? */

   write(STDOUT_FILENO, "Finished\n", strlen("Finished\n"));

   return 0;
}
