#include <stdio.h>

int mystery(int array[]);

int mystery(int array[]) {
   int *p = &array[0];  /* Is there a simple way to do this? */
   int sum = 0;

   while(*p != -1) {
      sum += *p;
      p++;
   }

   return sum;
}

int main() {
   int data[] = {11, 22, 5, -1, 2394, 45346};

   printf("Result is: %d\n", mystery(data));

   return 0;
}
