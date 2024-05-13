#include <stdio.h>
#include <stdint.h> /* Declares sets of integer types having specified widths */

#define PIX_GRN 0
#define PIX_RED 1
#define PIX_BLU 2

typedef int Scores[30];
typedef uint8_t Pixels[2][3];  /* uint8_t (unsigned int 8 bits) */

int main() {
   Scores scores = {100, 200}; /* scores is a one-dimensional array */

   /* all is a two-dimensional array */
   Pixels all = {{PIX_GRN, PIX_RED, PIX_BLU}, 
	         {PIX_RED, PIX_RED, PIX_RED}};

   printf("Scores values: %d, %d\n", scores[0], scores[1]);
   printf("pixel(1): %u %u %u\n", all[0][0], all[0][1], all[0][2]);

   return 0;
}
