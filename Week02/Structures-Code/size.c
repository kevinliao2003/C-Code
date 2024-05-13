#include <stdio.h>

struct one {
   int a;
   double b;
} s1;

struct two {
   char a;
   int b;
} s2;

int main(void) {
   printf("size of int %ld\n", sizeof(int));
   printf("size of double %ld\n", sizeof(double));
   printf("sizeof struct one %ld\n", sizeof(struct one));
   printf("sizeof struct two %ld\n", sizeof(struct two));

   return 0;
}
