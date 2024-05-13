#include <stdio.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include "serial.h"

extern uint8_t double_value(uint8_t n);

/* The following is a macro, expanded by the */
/* preprocessor. Do not use macrosas a wrong */
/* macro can cause difficult to find bugs.   */

#define RUN(x) printf(#x " is %d\n", x)

int main() {
   uint8_t inputs[] = { 1, 2, 8, 4, 0 }; /* 0 marks end of data */
   uint8_t i;

   init_serial_stdio();

   for(i = 0; inputs[i]; i++) { /* loop will stop when 0 is seen  */
      printf("%d -> %d\n", inputs[i], double_value(inputs[i]));
   }

   printf("Using RUN macro\n");
   RUN(double_value(30));
   RUN(double_value(40));

   cli();
   sleep_cpu();
}
