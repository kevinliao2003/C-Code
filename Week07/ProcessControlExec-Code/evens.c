#include <stdio.h>
#include <stdlib.h>

/* Prints values from 1 to up value
 * specified on the command line. If 
 * no value is specified, 100 is used.
 */

int main(int argc, char **argv) {
   int i, limit;
   
   /* Default of a 100; otherwise using command line arg */
   limit = (argc == 2 ? atoi(argv[1]) : 100);
   for (i = 1; i <= limit; i++) {
      if (i % 2 == 0) {
         printf("%d ", i);
      }
   }
   printf("\n");

   return 0;
}
