#include <stdio.h>

int main() {
   unsigned char a = 0x5f, b = 0xa1;
   unsigned char complement;

   unsigned char ones = 0;
   ones = ~ones;

   printf("Size of ones: %d\n", (int)sizeof(ones));
   printf("a AND b: %02x\n", a & b);
   printf("a AND 0: %02x\n", a & 0);
   printf("a AND ones: %02x\n", a & ones);
   printf("a OR b: %02x\n", a | b);
   printf("a OR 0: %02x\n", a | 0);
   printf("a OR ones: %02x\n", a | ones);
   printf("a XOR b: %02x\n", a ^ b);
   printf("a XOR 0: %02x\n", a ^ 0);
   printf("a XOR ones: %02x\n", a ^ ones);
   complement = ~a;
   printf("Complement of a: %02x\n", complement);

   return 0;
}
