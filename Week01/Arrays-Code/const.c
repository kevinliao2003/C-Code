#include <stdio.h>

void process_data_const(const int *p);
void process_ptr_const(int *const p);

void process_data_const(const int *p) {
  /* *p = 100; *//* Not possible  */
   printf("data constant value %d\n", *p);
   p = NULL;                    /* No problem */
}

void process_ptr_const(int *const p) {
   *p *= 2;
   printf("ptr constant %d\n", *p);
  /* p = NULL; problem */
}

void process_both_const(const int *const p) {
   /* *p *= 2; problem */
   /* p = NULL; probme */
   printf("data constant ptr and value %d\n", *p);
}

int main() {
   int i = 18;

   process_data_const(&i);
   process_ptr_const(&i);
   process_both_const(&i);

   return 0;
}
