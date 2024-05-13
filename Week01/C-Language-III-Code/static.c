#include <stdio.h>

void compute_automatic(int x);
void compute_static(int x);

void compute_automatic(int x) {
   int value = 100;

   printf("(automatic) x: %d, value: %d, sum: %d \n", x, value, value + x);
   
   ++value;
}

void compute_static(int x) {
   /* Initialization to a 100 will take place only once, when the */
   /* function is called the first time */
   static int value = 100; /* What would happen if we don't initialize it? */

   printf("(static) x: %d, value: %d, sum: %d \n", x, value, value + x);
   
   ++value;
}

int main() {
   compute_automatic(1);
   compute_automatic(1); /* calling function again */

   compute_static(1);
   compute_static(1); /* calling function again */

   return 0;
}
