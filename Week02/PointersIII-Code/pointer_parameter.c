#include <stdio.h>

void wrong_max_value(int *answer, int *v1_ptr, int *v2_ptr) {
   if (*v1_ptr >= *v2_ptr) {
      answer = v1_ptr;
   } else {
      answer = v2_ptr;
   }
}

/* Answer is ** pointer */
void correct_max_value(int **answer, int *v1_ptr, int *v2_ptr) {
   if (*v1_ptr >= *v2_ptr) {
      *answer = v1_ptr;
   } else {
      *answer = v2_ptr;
   }
}

int main() {
   int v1 = 10, v2 = 20;
   int *result = NULL;

   /* The following does not work */
   /* wrong_max_value(result, &v1, &v2); */

   correct_max_value(&result, &v1, &v2); 

   printf("Maximum: %d\n", *result);
   
   return 0;
}
