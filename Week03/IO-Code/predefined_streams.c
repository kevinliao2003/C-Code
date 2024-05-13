#include <stdio.h>
#include <stdlib.h> 

/* 
   Before running this example remove the files results.txt and
   errors_warnings.txt 
   by executing on the command line "make clean"*

   Try: (a.out < predefined_data.txt > results.txt) >& errors_warnings.txt 
 */

#define MAX_LEN 80

int main(void) {
   int max, i;

   printf("Enter positive value to generate table: ");
   fscanf(stdin, "%d", &max); /* Equivalent to scanf */

   /* If max < 1 output sent to standard error */
   if (max < 1) {
      fprintf(stderr, "Invalid value provided, using default\n");
      max = 5;
   }
   for (i = 1; i <= max; i++) {
      fprintf(stdout, "%d %d\n", i, i * i); /* Equivalent to printf */
   }

   return EXIT_SUCCESS;
}
