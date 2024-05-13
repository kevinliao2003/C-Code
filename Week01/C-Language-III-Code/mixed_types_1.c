#include <stdio.h>

int main() {
   int x = 2000000000; /* value fits in x */
   long result_long;

   printf("Value of x: %d\n", x);
   printf("Multiplying by 3 (with %%d format): %d\n", 2000000000 * 3);
   printf("Multiplying by 3 (with %%ld format): %ld\n", 2000000000 * 3);
   printf("Multiplying by 3L (with %%d format): %d\n", 2000000000 * 3L);
   printf("Multiplying by 3L (with %%ld format): %ld\n", 2000000000 * 3L);
  
   result_long = 2000000000 * 3;  /* Does it solve the problem? */
   printf("Storing result in long type variable: %ld\n", result_long);

   return 0;
}
