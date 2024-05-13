#include <stdio.h>

int main() {
   unsigned int value = 250;  /* try with 250 and 4000000000 */
   
   printf("\nType sizes\n");
   printf("sizeof(unsigned int): %ld\n", sizeof(unsigned int));
   printf("sizeof(int): %ld\n", sizeof(int));
   printf("sizeof(long): %ld\n\n", sizeof(long));

   printf("value: %u\n", value);
   printf("(int)value: %d\n", (int)value); 
   printf("(long)value: %ld\n", (long)value);

   printf("(int)value / 4: %d\n", (int)value / 4);
   printf("value / 4: %d\n", value / 4);

   return 0;
}
