#include <stdio.h>
#include <string.h>

static void process(const char *str) {
   long int k, value = 2;
   long int delta = (long int)strlen(str) - value;
   int answer_is_yes;
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
