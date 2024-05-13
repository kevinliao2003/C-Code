#include <stdio.h>

int main(void) {
   int a[3] = {10, 20, 30}, idx;
   char b[] = {'A', 'B', 'C'}; /* array size derived from initialization list */
   float c[4] = {1.5};  /* Not enough values, trailing elements set to 0 */

   for (idx = 0; idx < 3; idx++) {
      printf("%d ", a[idx]);
   }
   printf("\n");

   /* No size specified */
   for (idx = 0; idx < 3; idx++) {
      printf("%c ", b[idx]);
   }
   printf("\n");

   /* Only one initializer value */ 
   for (idx = 0; idx < 4; idx++) {
      printf("%f ", c[idx]);
   }
   printf("\n");
   
   return 0;
}
