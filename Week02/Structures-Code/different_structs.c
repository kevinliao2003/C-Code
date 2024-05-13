#include <stdio.h>

typedef struct pixel {
   int x, y;
   char color;
} Pixel;

typedef struct pixel2 {
   int x, y;
   char color;
} Pixel2;

int main(void) {
   Pixel p1, *p1_ptr;
   Pixel2 p2, *p2_ptr;
    
   /* p2 = p1;         */ /* invalid */ 
   /* p2_ptr = p1_ptr; */ /* invalid */

   return 0;
}

