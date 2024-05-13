#include <stdio.h>

int main(void) {
   unsigned char i = 0;  /* unsigned char is a byte */
   unsigned char limit1 = 255; 
   unsigned int k = 0, limit2 = 20;

   printf("unsigned char\n");
   printf("Limit: %02x\n", limit1); /* 2 digits printed out */
   for (i = 0; i <= limit1; i++) {
      printf("(%d,%02x) ", i, i);
      if (i == 255) {  /* Without break we have infinite loop */
         break;        /* as adding 1 to ff becomes 0 */
      }
   }

   printf("\nunsigned int\n");
   for (k = 0; k <= limit2; k++) {
      printf("(%d,%08x)\n", k, k); /* 8 digits printed out */
   }

   return 0;
}
