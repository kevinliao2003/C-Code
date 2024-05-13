#include <stdio.h>
#include <string.h>

static void process(const char *str) {
   size_t k, value = 2;
   size_t delta = strlen(str) - value; /* problem: possible negative */
   int answer_is_yes;                  /* value assigned to delta (unsigned) */
   char c;
   
   printf("Delta value: %ld\n", delta);
   printf("Enter \"yes\" to continue: ");
   answer_is_yes = scanf("ye%c", &c);
   if (answer_is_yes == 1) {
      for (k = 0; k < delta; k++) {
         printf("In loop %ld\n", k);
      }
   }
}

int main() {
  process("house");   /* problem when using "a" */

  return 0;
}
