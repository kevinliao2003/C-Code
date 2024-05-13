#include <stdio.h>

/* We can combine the structure definition and typedef */
typedef struct pixel {
   int x, y;
   char color;
} Pixel;

int main(void) {
   Pixel p1 = {1, 2, 'r'};
   Pixel p2 = {1};
   
   printf("p1: x: %d, y: %d, color: %c\n", p1.x, p1.y, p1.color);
   printf("p2: x: %d, y: %d, color: %c\n", p2.x, p2.y, p2.color);

   return 0;
}
