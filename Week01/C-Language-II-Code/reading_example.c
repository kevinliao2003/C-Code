/* 
 * Try running this example with different spacing 
 * between the gender and age (and before and after age).
 * Also using enter after and before entering a value.
 */

#include <stdio.h>

int main() {
   char gender = 'N';  /* Initializing them so we can see what */
   int age = -1;       /* happens when reading fails */

   printf("Enter gender(M/F) and age: ");
   scanf("%c%d", &gender, &age);  /* Forgetting the & is a common mistake */
   printf("Gender: %c, Age: %d\n", gender, age);

   return 0;
}
