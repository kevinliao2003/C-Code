#include <stdio.h>

typedef double Dollars;

void twice(Dollars d) {
   printf("%.2f\n", 2 * d);
}

int main() {
   Dollars x = 20.0;   
   double y;
   
   printf("%.2f\n", x);
   y = 30;
   x = y;
   printf("%.2f\n", x);
   twice(y); 

   return 0;
}
