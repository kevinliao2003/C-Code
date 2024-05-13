#include <stdio.h>

/*
 * 1. What happens if you add static at the beginning?
 * 2. What happens if you add extern?
 */

/* Function definition */
void print_sum(int limit) {
   int sum = 0, k = 1;    

   while (k <= limit) {
      sum += k;

      k++;
   }
   printf("The sum of %d is %d\n", limit, sum);
}
