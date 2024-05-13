#include <stdio.h>

int main() {
   int i, j = 2, k = 3;

   i = (1, ++j, ++k);
   printf("i: %d\n", i);
   printf("j: %d\n", j);
   printf("k: %d\n", k);

   /* Resetting j, k */
   printf("\nWithout parentheses\n");
   j = 2;
   k = 3;
   i = 1, ++j, ++k;
   printf("i: %d\n", i);
   printf("j: %d\n", j);
   printf("k: %d\n", k);

   return 0;
}
