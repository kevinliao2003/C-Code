#include <stdio.h>

typedef struct pixel {
   int x, y;
   char color;
} Pixel;

void print_pixel(Pixel p);
void increase_x_and_y(Pixel *p, int delta);

void print_pixel(Pixel p) {
   printf("x: %d, y: %d, color: %c\n", p.x, p.y, p.color);
}

void increase_x_and_y(Pixel *p, int delta) {
   p->x += delta;
   (*p).y += delta; /* We need parenthesis */
   /* *p.y += delta;  WRONG */
}

int main(void) {
   Pixel p1 = {1, 2, 'r'};
   Pixel *p1_ptr;
   
   p1_ptr = &p1;
   increase_x_and_y(p1_ptr, 300);
   print_pixel(p1);

   return 0;
}
