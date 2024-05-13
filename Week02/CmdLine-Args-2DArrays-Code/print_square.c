#include <stdio.h>
#include <stdlib.h>  /* For atoi() */

int main(int argc, char **argv) { /* Notice definition of argv */
   /* Approach to verify correct number of command line arguments */
   if (argc != 2) {
      printf("Usage: %s <number>\n", argv[0]);
   } else {
      int value = atoi(argv[1]); /* We need to covert string to int */
      printf("%d-->%d\n", value, value * value);
   }

   return 0;
}
