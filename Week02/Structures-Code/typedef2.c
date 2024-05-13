#include <stdio.h>

/* Next two are NOT the same */
#define INT_PTR_DEFINE int *

typedef int * INT_PTR_TYPEDEF;

int main(void) {
   INT_PTR_TYPEDEF x_ptr, y;  /* Try with INT_PTR_DEFINE */
   int x = 200; 

   x_ptr = &x;
   printf("x value via pointer %d\n", *x_ptr);
   y = &x;  /* PROBLEM: y is NOT a pointer variable when using #define */
            /* y is a pointer variable when using typedef */

   return 0;
}
