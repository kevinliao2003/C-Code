#include <stdio.h>

int main() {
   int *p = NULL;

   *p = 200;  /* What will happen? */
 
   printf("The value is %d\n", *p);

   return 0;
}
