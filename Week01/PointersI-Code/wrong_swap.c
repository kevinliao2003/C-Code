#include <stdio.h>

void wrong_swap(int a, int b) {
   int tmp = a;

   a = b;
   b = tmp;
}

int main() {
   int x = 2, y = 3;

   wrong_swap(x, y);
   printf("%d %d\n", x, y); 

   return 0;
}
