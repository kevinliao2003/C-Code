#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Try running the example with more than MAX elements */

#define MAX 30

int compare_ints_func(const void *x, const void *y);

int compare_ints_func(const void *x, const void *y) {
   return *(int *)x - *(int *)y;
}

int main(void) {
   int count, data[MAX], i;

   /* Reading array values */
   printf("Enter number of integer values to sort (no more than %d): ", MAX);
   scanf("%d", &count);
   assert(count <= MAX);  /* Notice use of assert */
   for (i = 0; i < count; i++) {
      printf("Enter value: ");
      scanf("%d", &data[i]);
   }

   /* Sorting using qsort */ 
   qsort(data, count, sizeof(int), compare_ints_func);

   /* Printing */
   printf("Sorted values: ");
   for (i = 0; i < count; i++) {
      printf("%d ", data[i]);
   }
   printf("\n");

   return 0;
}
