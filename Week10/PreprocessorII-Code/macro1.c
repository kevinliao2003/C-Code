#include <stdio.h>

#define VAL "My Name is Harry Potter"
#define SUM(a, b) ((a) + (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

/* Don't do this; it is confusing (see expression below) */
#define DIVIDED_BY_HUNDRED / 100.0

int main(void) {
   int x = 90;

   printf("%s\n", VAL);
   printf("SUM(3, 5) = %d\n", SUM(3, 5));
   printf("SUM(14, 9) = %d\n", SUM(14, 9));
   printf("MIN(3, 5) = %d\n", MIN(3, 5));
   printf("MIN(14, 9) = %d\n", MIN(14, 9));
   printf("Value = %f\n", x DIVIDED_BY_HUNDRED);

   return 0;
}
