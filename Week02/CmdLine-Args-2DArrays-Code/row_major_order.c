#include <stdio.h>

#define MAX_COLS 4

int main(void)  {
   int data[][MAX_COLS] = {{5, 10, 15, 20},
                           {25, 30, 35, -1}};
                     
   /* Printing array to show that rows are */
   /* stored one after another in memory.  */
   int *p = data[0];
   while (*p != -1) {
      printf("%d ", *p++);
   }
   printf("\n");

   return 0;
}
