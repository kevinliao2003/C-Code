#include <stdio.h>

typedef struct pixel {
   int x, y;
   char color;
} Pixel;

void print_pixel(Pixel p);
Pixel increase_x_value(Pixel p, int delta);
Pixel increase_y_value(Pixel p, int delta);

void print_pixel(Pixel p) {
   printf("x: %d, y: %d, color: %c\n", p.x, p.y, p.color);
}

Pixel increase_x_value(Pixel p, int delta) {
   Pixel new_pixel = p;
   new_pixel.x += delta;

   return new_pixel;
}

Pixel increase_y_value(Pixel p, int delta) {
   p.y += delta;

   return p;
}

int main(void) {
   Pixel p1 = {1, 2, 'r'}, increased;
   
   print_pixel(p1);
   increased = increase_y_value(p1, 100);
   print_pixel(increased);
   print_pixel(p1);
   print_pixel(increase_y_value(p1, 400));

   return 0;
}
