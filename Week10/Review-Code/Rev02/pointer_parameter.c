#include <stdio.h>

static int is_valid_age(int **p) {
   if (**p < 0) {
      *p = NULL;
      return 0;
   } else {
      return 1;
   }
}

int main() {
   int age, *age_ptr = &age;

   printf("Enter age (integer): ");
   scanf("%d", age_ptr);  /* Notice no & */
   if (is_valid_age(&age_ptr)) {
      printf("Correct age value provided: %d\n", age);
   } else {
      printf("Incorrect age value provided\n");
      if (age_ptr) {
         printf("Error: pointer variable must be NULL\n");
      } else {
         printf("age_ptr is NULL\n");
      }
   }
   
   return 0;
}
