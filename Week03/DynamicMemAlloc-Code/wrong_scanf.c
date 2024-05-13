#include <stdio.h>

int main(void) {
   char c;

   printf("Enter a character: ");
   scanf("%1s", &c);  /* THIS IS WRONG!!! */
   printf("Provided character is: %c\n", c);

   return 0;
}
