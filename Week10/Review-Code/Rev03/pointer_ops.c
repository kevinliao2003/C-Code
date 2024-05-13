#include <stdio.h>

int main() {
   int data[] = {10, 20, 30, 40};
   int *m = data, *pd3 = data + 3, *pd4 = data + 4;

   printf("%d %d\n", *m, *pd3);
   printf("Difference: %ld\n", pd3 - m);
   printf("Difference Two: %ld\n", m - pd3);
   printf("Negative index: %d\n", pd4[-2]); /* BAD */
   printf("%p\n", (void *)pd4);  /* Can we dereference pd4? */

   return 0;
}
