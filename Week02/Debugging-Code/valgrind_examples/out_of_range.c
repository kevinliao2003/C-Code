/******************************/
/* This code has an error not */
/* reported by the compiler.  */
/******************************/
#include <stdio.h>

static void process(int b[], int size) {
   int i;

   for (i = size; i >= 0; i--) {
      if (b[i] > b[i - 1]) {  /* incorrect */
         printf("Greater than\n");
      }
   }
}

int main() {
   int a[3] = {10, 20, 30}, size = 3;

   process(a, size);

   return 0;
}
