#include <stdio.h>

#define ARRAY_LENGTH 3
#define SCHOOL "UMCP"
#define BEGIN {
#define END }
#define EXTRA ARRAY_LENGTH + 1

int main() BEGIN
   int i, a[ARRAY_LENGTH] = { 10, 20, 30 };
   int *p = a;
   int b[EXTRA];

   printf("[%d", a[0]);
   for (i = 1; i < ARRAY_LENGTH; i++) {
      printf(", %d", a[i]);
   }
   printf("]\n");
   printf("School SCHOOL %s\n", SCHOOL);
   printf("Size of array: %ld\n", sizeof(a));
   printf("Size of ptr: %ld\n", sizeof(p));
   printf("%d\n", p[1]);

   return 0;
END
