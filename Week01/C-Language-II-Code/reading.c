#include <stdio.h>

int main() {
   int value;
   char the_character;

   printf("Enter an integer: ");
   scanf("%d", &value);
   printf("First integer value is %d\n", value);

   printf("\nEnter a character and an integer: ");

   /* We need a space before %c; this space means consume spaces. */
   /* After the first integer we provided we have a newline. This */
   /* newline is the result of pressing enter.  If you don't      */
   /* remove it, the_next_character variable will have a newline  */
   /* character.  Remember, when you press enter that is actually */
   /* the '\n' character.                                         */

   /* Notice space before %c. */
   scanf(" %c%d", &the_character, &value);
   printf("The character is %c\n", the_character);
   printf("The second integer value is %d\n", value);

   return 0;
}
