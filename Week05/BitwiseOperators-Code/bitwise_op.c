#include <stdio.h>

int main(void) {
   unsigned int a = 0x5555ffff, b = 0xaaaa1111;
   unsigned int ones = 0;
   ones = ~ones;

   printf("a AND b: %08x\n", a & b);
   printf("a AND 0: %08x\n", a & 0);
   printf("a AND ones: %08x\n", a & ones);
   printf("a OR b: %08x\n", a | b);
   printf("a OR 0: %08x\n", a | 0);
   printf("a OR ones: %08x\n", a | ones);
   printf("a XOR b: %08x\n", a ^ b);
   printf("a XOR 0: %08x\n", a ^ 0);
   printf("a XOR ones: %08x\n", a ^ ones);
   printf("Complement of a: %08x\n", ~a);

   return 0;
}
