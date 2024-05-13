#include <stdio.h>

/* INC defined before NUM */
#define INC 1 + NUM
#define NUM 100
#define VAL "My Name is Harry Potter"
#define SUM(a,b) ((a) + (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define PRINT_SIZE(type) \
    printf("%ld\n", sizeof(type))

int main(void) {
   printf("VAL = %s\n", VAL);
   printf("SUM(3, 5) = %d\n", SUM(3, 5));
   printf("SUM(14, 9) = %d\n", SUM(14, 9));
   printf("MIN(3, 5) = %d\n", MIN(3, 5));
   printf("MIN(14, 9) = %d\n", MIN(14, 9));
   printf("MIN(NUM, 500) = %d\n", MIN(NUM, 500));
   printf("MIN(MIN(NUM,5), 500) = %d\n", MIN(MIN(NUM, 5), 500));
   printf("INC = %d\n", INC);
   printf("Size int: ");
   PRINT_SIZE(int);

   return 0;
}
