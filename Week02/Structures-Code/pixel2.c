#include <stdio.h>

struct pixel { /* We could have used Pixel as the tag */
   int x, y;
   char color;
};

typedef struct pixel Pixel;

int main() {
   Pixel p1, all_pixels[2];
   
   p1.x = 1;
   p1.y = 2;
   p1.color = 'r';
   all_pixels[0].x = 4;
   all_pixels[0].y = 5;
   all_pixels[0].color = 'b';
   all_pixels[0].x++;

   printf("pixel: x: %d, y: %d, color: %c\n", p1.x, p1.y, p1.color);

   return 0;
}
