#include <stdio.h>

int main() {
   int limit, done, curr;
 
   /* Reading a positive value */
   do {
      printf("Enter limit to print even/odd values: ");
      scanf("%d", &limit);
      done = limit > 0; 
      if (!done) {
         printf("Invalid value %d provided (must be > 0)\n", limit);
      }
   } while(!done);

   /* Printing even values */ 
   printf("Even values up to %d: ", limit);
   curr = 2;
   while(curr <= limit) {
      printf("%d ", curr);

      curr += 2;
   }
   printf("\n"); 

   /* Printing odd values */
   printf("Odd values up to %d: ", limit);
   for (curr = 1; curr <= limit; curr += 2) {
      printf("%d ", curr);
   }
   printf("\n"); 

   return 0;
}
