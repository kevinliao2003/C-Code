#include <stdio.h>

typedef union {
   int i;
   double d;
} Number;

int main(void) {
   Number num;

   printf("sizeof(int): %ld\n", sizeof(int));
   printf("sizeof(double): %ld\n", sizeof(double));
   printf("sizeof(Number): %ld\n\n", sizeof(Number));

   num.i = 2;
   printf("Initializing num.i to %d\n", num.i);
   printf("num.i: %d\n", num.i);
   printf("num.d: %f\n\n", num.d);

   num.d = 3.4;
   printf("Initializing num.d to %f\n", num.d);
   printf("num.i: %d\n", num.i); /* int is interpreted as a double, since this is a union */
   printf("num.d: %f\n\n", num.d);

   return 0;
}
