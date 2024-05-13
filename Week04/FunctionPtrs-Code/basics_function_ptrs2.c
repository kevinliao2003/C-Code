#include <stdio.h>

/* All functions must have the same prototype so we 
 * can assign them to the function pointer variable.
 */

void print_decimal(unsigned int i);
void print_hex(unsigned int i);
void print_octal(unsigned int i);

void print_decimal(unsigned int i) {
   printf("%u\n", i);
}

void print_hex(unsigned int i) {
   printf("%x\n", i);
}

void print_octal(unsigned int i) {
   printf("%o\n", i);
}

int main(void) {
   void (*fp)(unsigned int); /* Function pointer */

   /* & and * are optional */
   fp = print_hex; /* print_hex assigned to function pointer */
   fp(16);  /* Prints "10" */
   fp = &print_octal; /* print_octal assigned to function pointer */
   fp(16);  /* Prints "20" */
   fp = print_decimal; /* print_decimal assigned to function pointer */
   (*fp)(16);  /* Prints "16" */

   return 0;
}
