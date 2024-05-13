#include <stdio.h>

void correct_swap(int *a, int *b) {
   int tmp = *a;

   *a = *b;
   *b = tmp;
}

int main() {
   int x = 2, y = 3;
   int *x_ptr = &x;  /* some use _ptr to label pointer variables */
   int *y_ptr = &y;

   correct_swap(x_ptr, y_ptr); /* we could have used correct_swap(&x, &y) */
   printf("%d %d\n", x, y); 

   return 0;
}
