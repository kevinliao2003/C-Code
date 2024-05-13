#include <stdio.h>
#include <math.h>

int main(void) {
   float value;

   printf("Looking at shared libraries\n");
   printf("Enter value to computer square root: ");
   scanf("%f", &value);
   printf("Square root of %f: %f\n", value, sqrt(value));

   return 0;
}
