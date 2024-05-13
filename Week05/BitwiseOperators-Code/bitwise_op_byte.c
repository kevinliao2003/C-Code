#include <stdio.h>

int main(void) {
   unsigned char a = 0x5f, b = 0xa1, complement;
   unsigned char ones = 0;
   ones = ~ones; 

   printf("a: %02x\n", a); /* 5f */
   printf("b: %02x\n", b); /* a1 */
   printf("ones: %02x\n", ones); /* ff */
   printf("a & b: %02x\n", a & b);
   printf("a & 0: %02x\n", a & 0);
   printf("a & ones: %02x\n", a & ones); /* 5f */
   printf("a | b: %02x\n", a | b);
   printf("a | 0: %02x\n", a | 0); /* 5f */
   printf("a | ones: %02x\n", a | ones); /* ff */
   printf("a ^ b: %02x\n", a ^ b);
   printf("a ^ 0: %02x\n", a ^ 0);
   printf("a ^ ones: %02x\n", a ^ ones); /* a0 */
   complement = ~a; /* a0 */
   printf("Complement of a: %02x\n", complement);

   return 0;
}
