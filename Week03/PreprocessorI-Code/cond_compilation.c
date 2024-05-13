/*
 * You can control debugging activity as follows:
 * Enabling debugging --> #define MY_DEBUG 1  
 * Enabling debugging --> gcc -DMY_DEBUG cond_compilation.c 
 *
 * In this example debugging is disabled by default.
 *
 */

#include <stdio.h>

int main(void) {
   int a = 20, b = 3;

   int c = a * b;

#if defined(MY_DEBUG)
   printf("(Debugging) Value of a is %d\n", a);
   printf("(Debugging) Value of b is %d\n", b);
   printf("(Debugging) Value of c is %d\n", c);
#else
   printf("Processing:\n");
#endif
   printf("Result: %d\n", c);

   return 0;
}
