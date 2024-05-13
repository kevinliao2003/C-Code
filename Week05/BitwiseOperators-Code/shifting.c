#include <stdio.h>
#include <stdint.h>

int main(void) {
   uint8_t c = 0x55;     /* Using uint8_t part of stdint.h */
   unsigned int a = 16;  /* 16 decimal, not hex */

   printf("*****\n");
   printf("Shifting 0x%02x\n", c);
   printf("c <<= 2: 0x%02x\n", c <<= 2);
   printf("c >>= 3: 0x%02x\n", c >>= 3);

   printf("Shifting 0x%08x (Decimal %d) \n", a, a);
   printf("a << 1: 0x%08x (Decimal %d) \n", a << 1, a << 1);
   printf("a << 2: 0x%08x (Decimal %d) \n", a << 2, a << 2);
   printf("a >> 1: 0x%08x (Decimal %d) \n", a >> 1, a >> 1);
   printf("a >> 2: 0x%08x (Decimal %d) \n", a >> 2, a >> 2);
   printf("a after shifting 0x%08x (Decimal %d) \n", a, a);

   return 0;
}
