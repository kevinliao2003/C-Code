#include <stdio.h>
#include <stdlib.h>

#define COUNT 5

int main(void) {
   int *p1 = calloc(COUNT, sizeof(int));
 
   free(p1 + (COUNT - 1)); /* WRONG, address is not pointing to beginning */
                           /* of dynamically-allocated block */
   return 0;
}
