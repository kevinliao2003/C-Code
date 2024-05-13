#include <stdio.h>

static void process(void *data_ptr, int type);

static void process(void *data_ptr, int type) {
   int int_value;
   float float_value;

   if (type == 1) {
      int_value = *(int *)data_ptr;
      printf("int value provided %d\n", int_value);
   } else if (type == 2) {
      float_value = *(float *)data_ptr;
      printf("float value provided %f\n", float_value);
   } else {
      printf("Invalid type provided\n");
   }
}

int main() {
   int int_value = 200;     
   float float_value = 4.4f, *f_ptr;
   void *v_ptr;

   /* You can assign any address to a void pointer variable */
   v_ptr = &int_value; /* assigning to void pointer variable a pointer to float */
   v_ptr = &float_value; /* assigning to void pointer variable a pointer to int */

   /* printf("%f\n", *v_ptr); we cannot dereference a void ptr */
   printf("V1: %f\n", *(float *)v_ptr); 

   /* You can assign a void pointer value to an integer/float/ pointer variable etc.  */
   f_ptr = v_ptr;
   printf("V2: %f\n", *f_ptr); 

   /* void pointers allow us to pass any data */
   process(&int_value, 1);
   process(&float_value, 2);

   return 0;
}
