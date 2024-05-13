#include <stdio.h>

int main() {
   int x = 20;
   int *ptr = &x;

   printf("Value of x is: %d\n", x);
   printf("Size of integer in bytes is: %ld\n", sizeof(x));
   printf("Value of x via pointer is: %d\n", *ptr);
   printf("Size of pointer variable in bytes is: %ld\n", sizeof(ptr));
   printf("Pointer value is: %p\n", (void *)ptr);
   
   return 0;
}
