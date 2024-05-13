#include <stdio.h>

int main(void) {
   float float_value = 1.0f/5.0;
   double double_value = 1.0/5.0;
   long double long_double_value = 1.0L/5.0;

   printf("\n%-20s%.2f\n", "float_value", float_value);
   printf("%-20s%.6f\n", "float_value", float_value);
   printf("%-20s%.7f\n", "float_value", float_value);
   printf("%-20s%.8f\n", "float_value", float_value);
   printf("%-20s%.20f\n", "float_value", float_value);
   printf("%-20s%.26f\n", "float_value (26)", float_value);
   printf("%-20s%.27f\n", "float_value", float_value);
   printf("%-20s%.28f\n", "float_value", float_value);
   printf("%-20s%.29f\n", "float_value", float_value);
   printf("%-20s%.40f\n", "double value", double_value);
   printf("%-20s%.40Lf\n\n", "long double value", long_double_value);

   return 0;
}
