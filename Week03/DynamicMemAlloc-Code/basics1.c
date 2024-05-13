#include <stdio.h>
#include <stdlib.h>  /* For malloc, EXIT_FAILURE, EXIT_SUCCESS */

int main(void) {
   int *ip, i, array_length = 3;

   /* Allocating space for an integer */
   ip = malloc(sizeof(int)); /* Casting is not necessary */
   if (ip == NULL) {
      exit(EXIT_FAILURE);
   }
   *ip = 104;
   printf("Value assigned is %d\n", *ip);
   free(ip); /* deallocating memory */



   /* Allocating space for array */
   ip = malloc(sizeof(int) * array_length);
   if (ip == NULL) {
      exit(EXIT_FAILURE);
   }
   for (i = 0; i < array_length; i++){
      ip[i] = i * 3;
   }
   for (i = 0; i < array_length; i++){
      printf("%d ",ip[i]); /* Using array indexing */
   }
   printf("\n");
   free(ip); /* Deallocating memory */
       


   /* Allocating another array */
   ip = calloc(array_length, sizeof(int));
   if (ip == NULL) {
      exit(EXIT_FAILURE);
   }
   for (i = 0; i < array_length; i++){
      ip[i] = i * 4;
   }
   for (i = 0; i < array_length; i++){
      printf("%d ",ip[i]); /* Using array indexing */
   }
   printf("\n");
   free(ip); /* Deallocating memory */

   return EXIT_SUCCESS;
}
