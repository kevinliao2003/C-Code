#include <stdio.h>

void print_array(int data[], int length);
void double_array(int *data, int length);
char is_all_zeros(const int *data, int length);

void print_array(int data[], int length) {
   int i; 

   /* Do not use sizeof(data) instead of length.
    * sizeof(data) will return size of int * and
    * not the size of the array.
    */
   for (i = 0; i < length; i++) {
      printf("%d ", data[i]);
   }
   printf("\n");
}

void double_array(int *data, int length) {
   int i;

   for (i = 0; i < length; i++) {
      data[i] *= 2;
   }
}

char is_all_zeros(const int * const data, int length) {
   int i;

   for (i = 0; i < length; i++) {
      if (data[i] != 0) {
         return 'n';
      }   
   }

   return 'y';
}

int main() {
   int a[] = {10, 3, 67};
   int b[3] = {0};
   int length = 3;

   print_array(a, length);
   printf("All zeros: %c\n\n", is_all_zeros(a, length));

   print_array(b, length);
   printf("All zeros: %c\n\n", is_all_zeros(b, length));

   double_array(a, length); 
   print_array(a, length);

   return 0;
}
