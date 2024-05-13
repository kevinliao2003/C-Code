/******************************/
/*   This code has an error   */
/******************************/
#include <stdio.h>

int main() {
   int y = 100, values_read;

   values_read = scanf("%d", &y);
   if (values_read != 1) {
      printf("Error reading values\n");
   }

   if (y > 0); {
      printf("Positive\n");
   }

   return 0;
}
