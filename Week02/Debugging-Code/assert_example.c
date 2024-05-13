#include <stdio.h>
#include <assert.h>

int main() {
   int x;
   
   printf("Enter 0 or positive value: ");
   scanf("%d", &x);
   assert(x >= 0);

   printf("Square of %d is %d\n", x, x * x);

   return 0;
}
