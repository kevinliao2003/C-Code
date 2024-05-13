#include <stdio.h>

/* Never return a pointer */
/* to a local variable    */          

int *get_value_wrong();
int add_value(int y);

int *get_value_wrong() {
   int x = 4;

   return &x;
}

int add_value(int y) {
   int a = 5;

   return a + y;
}

int main(void) {
   int *first_result_ptr, second_result;

   first_result_ptr = get_value_wrong();
   printf("First result %d\n", *first_result_ptr);

   second_result = add_value(3);
   printf("Second result %d\n", second_result);

   printf("First result (changed?) %d\n", *first_result_ptr);

   return 0;
}
