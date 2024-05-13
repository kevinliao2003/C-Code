#include <stdio.h>

typedef struct {
   enum { INT, DOUBLE } type;
   union {
      int i;
      double d;
   } value;
} Better_number;

void print_number(Better_number num) {
   switch (num.type) {
      case INT:
         printf("%d", num.value.i);
         break;
      case DOUBLE:
         printf("%f", num.value.d);
         break;
      default:
         printf("?????");
         break;
   }
   printf("\n");
}

int main(void) {
   Better_number num1;

   num1.type = INT;
   num1.value.i = 20;
   print_number(num1);

   num1.type = DOUBLE;
   num1.value.d = 103.45;
   print_number(num1);
 
   return 0;
}
