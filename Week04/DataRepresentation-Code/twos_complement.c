#include <stdio.h>

int main(void) {
   printf("Size of signed int (bytes): %ld\n", sizeof(signed int));
   printf("Size of signed int (bits): %ld\n", 8 * sizeof(signed int));

   /* Using %08 as we have 8 hexadecimal characters */
   printf("1 in hexadecimal: 0x%08x\n", (signed int) 1); 
   printf("-1 in hexadecimal: 0x%08x\n", (signed int) -1); 
   printf("5 in hexadecimal: 0x%08x\n", (signed int) 5); 
   printf("-5 in hexadecimal: 0x%08x\n", (signed int) -5); 

   return 0;
}
