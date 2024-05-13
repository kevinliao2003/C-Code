#include <stdio.h>
#include "first.h"
#include "second.h"

int main() {
   int val1, val2;

   printf("Enter 2 integers: ");
   scanf("%d%d", &val1, &val2);
   printf("first(%d) = %d\n", val1, a(val1));
   printf("first(%d) = %d\n", val2, b(val2));
   printf("second(%d) = %d\n", val1, c(val1));
   printf("second(%d) = %d\n", val2, d(val2));

   return 0;
}
