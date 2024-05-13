#include <stdio.h>
#include <stdint.h>

uint16_t flip_clear_nibbles(uint16_t x) {
   return (x >> 4 & 0x00F0) | (x << 4 & 0x0F00);
}

int main(void) {
   printf("%04x\n", flip_clear_nibbles(0xabcd));

   return 0;
}
