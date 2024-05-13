#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int x, y;
} Point;

int main(void) {
   Point point = {3, 4}, *p1 = &point;

   printf("point: %d, %d\n", point.x, point.y);
   printf("p1: %d, %d\n", p1->x, p1->y);

   /* The following free is WRONG */
   free(p1); 

   return 0;
}
