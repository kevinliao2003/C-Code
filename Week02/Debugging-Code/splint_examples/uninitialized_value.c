/*******************************/
/*   This code has an error    */
/*******************************/
#include <stdio.h>

int main() {
   int y, total_values, values_read;

   values_read = scanf("%d", &y);
   if (values_read != 1) {
      printf("Error reading values\n");
   }

   if (y > 0) {
      printf("Positive\n");
      total_values += 100;
   } else {
      total_values += 200;
   }

   printf("total_values: %d\n", total_values);

   return 0;
}
