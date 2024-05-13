#include <stdio.h>  /* Includes perror */
#include <string.h> /* For strerror */
#include <errno.h>  /* Allows access to errno */

int main(void) {

   printf("errno value 1: %d\n", errno);
   perror("first");
   printf("errno value 2: %d\n", errno);
   perror("terps");

   /* Attempting to open invalid file */ 
   fopen("bla.txt", "r");
   printf("errno value 3: %d\n", errno);

   /* Using perror */
   perror("\nThis is our message: ");
   printf("errno value 4: (using perror does not reset errno): %d\n", errno);

   /* Using strerror */
   printf("\nThe message printed by strerror: %s\n\n", strerror(errno));

   return 0;
}
