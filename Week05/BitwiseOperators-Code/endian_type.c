#include <stdio.h>

int main(void) {
   unsigned int value = 0x01234567; /* 4 bytes */
   unsigned char *value_ptr = (unsigned char *)&value;
   int i;

   printf("Value %08x\n", value);
   if (*value_ptr == 0x67) {
      printf("It is little endian\n");
   } else {
      printf("It is Big endian\n");
   }
   printf("Bytes: ");
   for (i = 1; i <= 4; i++, value_ptr++) {
      printf("%02x", *value_ptr);
   }
   printf("\n");

   return 0;
}
