#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int x, y;
} Point;

int main(void) {
   Point *p1;

   p1 = malloc(sizeof(Point));   /* No casting needed */
   if (p1 == NULL) {
      exit(EXIT_FAILURE);
   }

   p1->x = 5;
   p1->y = 9;
   printf("p1's data before free:%d %d\n", p1->x, p1->y);
   free(p1);  /* After free p1, is a dangling pointer */

   /* We should not be accessing/using p1 as it is a dangling pointer */
   /* The following is WRONG */
   printf("p1's data: %d %d\n", p1->x, p1->y);  

   return 0;
}
