#include <stdio.h>

/* 
 * 1. What happens if you add static at the beginning of the prototype? 
 * 2. What happens if you add extern at the beginning of the prototype?
 * 3. What happens if you remove the prototype?
 */

void print_sum(int limit); /* Prototype */

int main() {
   print_sum(4);

   return 0;
}
