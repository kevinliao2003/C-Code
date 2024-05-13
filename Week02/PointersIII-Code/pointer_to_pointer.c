#include <stdio.h>

int main() {
   int i = 4;
   int j = 6;
   int *p = &i;
   int *q = &j;
   int **r = &p;

   printf("%d\n", **r);
   *r = &j;
   printf("%d\n", *p);
   printf("%d\n", *q);

   return 0;
}
