#include <stdio.h>

void *memcpy(void *dst, void *src, size_t n) {
   char *dp = dst;
   char *sp = src;

   while ((size_t)(dp - (char *) dst) < n) {
      *dp++ = *sp++;
   }

   return dst;
}

int main(void) {
   int i, j = 5;

   memcpy(&i, &j, sizeof(int));
   printf("%d\n", i);

   return 0;
}
