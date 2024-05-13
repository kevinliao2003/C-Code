/******************************/
/* This code has an error not */
/* reported by the compiler.  */
/* splint will detect it      */
/******************************/
#include <stdio.h>

static int twice(float x) {
   return x * 2.0f;
}

int main() {
   float y = 4.2f, result;

   result = twice(y);
   printf("Twice the value of %f is is %f\n",  y, result);

   return 0;
}
