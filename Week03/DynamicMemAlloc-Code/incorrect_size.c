#include <stdio.h>
#include <string.h>

int main(void) {
   /* THE FOLLOWING WRONG compution is a problem    */ 
   /* we have seen often.  Make sure you don't make */
   /* the same mistake.                             */

   size_t wrong_computation = sizeof(strlen("FearTheTurtleMDMascot")) + 1;
   size_t correct_computation = strlen("FearTheTurtleMDMascot") + 1;

   printf("Wrong Length: %ld\n", wrong_computation);
   printf("Correct Length: %ld\n", correct_computation);

   return 0;
}
