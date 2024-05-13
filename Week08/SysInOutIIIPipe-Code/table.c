#include <stdio.h>
#include <math.h>

int main(void) {
   int i, limit;

   scanf("%d", &limit); 
   printf("Table Max Value %d\n", limit);
   for (i = 1; i <= limit; i++) {
      printf("|%6d|%10f|\n", i, sqrt(i)); 
   }

   return 0;
}
