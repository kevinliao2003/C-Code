#include <stdio.h>

/* 
 * 1. What happens if we remove extern?
 * 2. What happens if we assign a value to g_computers ?
 * 3. What happens if we assign a value to g_computers having a extern? 
 * 4. What if we remove the extern and assign a value to g_computers?
 */

/* Declaration */
extern int g_computers;

/* Function prototype */
void process();

int main() {
   printf("Before calling process %d\n", g_computers);
   process();
   printf("After calling process %d\n", g_computers);

   return 0;    
}
