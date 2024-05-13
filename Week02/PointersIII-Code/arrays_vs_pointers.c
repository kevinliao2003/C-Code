#include <stdio.h>

void print_array(const int *p, int size) {  /* const int *p could have been */
                                            /* written as const int p[] */
   int idx = 0;
   for (idx = 0; idx < size; idx++) {
      printf("%d\n", p[idx]);
   }

   printf("In print_array size of array using sizeof: %ld\n", sizeof(p));
}

int main() {
   int data[] = {10, 20, 30, 40, 50, 60};

   print_array(data, 3);
   /* data = NULL;  What happens if we try this assignment? */

   printf("In main size of data array using sizeof: %ld\n", sizeof(data));

   return 0;
}
