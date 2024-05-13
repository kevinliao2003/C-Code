#include <stdio.h>
#include "my_point.h"
#include "my_cost_point.h"

int main() {
   My_point p;
   My_cost_point cp;

   p.x = 8;
   p.y = 12;
   printf("p = (%d,%d)\n", p.x, p.y);

   cp.p.x = 100;
   cp.p.y = 200;
   cp.cost = 3.4;
   printf("cp = (%d, %d, %f)\n", cp.p.x, cp.p.y, cp.cost);

   return 0;
}
