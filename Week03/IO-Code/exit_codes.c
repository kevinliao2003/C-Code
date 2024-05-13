#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>

int main(void) {
   printf("EXIT_SUCCESS %d\n", EXIT_SUCCESS);
   printf("EXIT_FAILURE %d\n", EXIT_FAILURE);

   /* EX_OSERR: operating system error */
   printf("EX_OSERR %d\n", EX_OSERR); 

   /* EX_USAGE: incorrect use of command (e.g., wrong args) */
   printf("EX_USAGE %d\n", EX_USAGE);

   return EXIT_SUCCESS;
}
