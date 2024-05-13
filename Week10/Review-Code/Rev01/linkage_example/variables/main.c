#include <stdio.h>

/* 
 * 1. What happens if we remove extern?
 * 2. What happens if we assign a value  to My_Global?
 */

extern int My_Global;

void process();

int main() {
   printf("Before calling process %d\n", My_Global);
   process();
   printf("After calling process %d\n", My_Global);

   return 0;    
}
