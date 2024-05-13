#include <stdio.h>
#include <assert.h>

void process(int int_value) {
   float *float_ptr = (float *) &int_value;

   printf("Processing %d\n", int_value);
   printf("%d\n", int_value);
   printf("%f\n", *float_ptr);
   printf("%f\n", (float) int_value);
   printf("%u\n", (unsigned int) int_value);
}

int main() {
   /* Making sure same number of bytes */
   printf("sizeof(float) %ld\n", sizeof(float));
   assert(sizeof(float) == sizeof(int)); 
   assert(sizeof(unsigned int) == sizeof(int)); 

   process(64);
   process(-64);

   return 0;
}
