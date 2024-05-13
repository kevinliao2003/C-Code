#include <stdio.h>
#include <string.h>

int main(void) { /* notice void in main */
   int i = 5;

   printf("initial value of i: %d\n", i);
   printf("i (int) size in bytes: %ld\n", sizeof(i));
   printf("unsigned char size in bytes: %ld\n", sizeof(unsigned char));
   printf("i++ size in bytes: %ld\n", sizeof(++i)); /* Increment will NOT take place */
   printf("final value of i: %d\n", i); /* Still 5 not 6 */
   printf("sizeof(100) in bytes: %ld\n", sizeof(100));

   return 0;
}
