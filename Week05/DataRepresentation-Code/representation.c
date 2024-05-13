#include <stdio.h>
#include <assert.h>

void process(unsigned int unsigned_int) {
   printf("Val %u as float %f\n", unsigned_int,  *(float *)&unsigned_int);
   printf("Val %u as int %d\n", unsigned_int,  *(int *)&unsigned_int);
   printf("Val %u casted to float %f\n", unsigned_int, (float)unsigned_int);
   printf("Val %u casted to int %d\n\n", unsigned_int, (int)unsigned_int);
}

int main() {
   unsigned int unsigned_int = 3445054489; 
   printf("\nsizeof(float): %ld bytes\n", sizeof(float));
   printf("sizeof(unsigned int): %ld bytes\n", sizeof(unsigned int));
   printf("sizeof(int): %ld bytes\n\n", sizeof(int));

   /* Making sure same number of bytes for the specified types  */
   assert(sizeof(float) == sizeof(unsigned int)); 
   assert(sizeof(unsigned int) == sizeof(int)); 

   printf("Example #1\n");
   unsigned_int = 64;
   process(unsigned_int);
  
   printf("Example #2\n");
   unsigned_int = 3445054489;   
   process(unsigned_int);

   printf("Example #3\n");
   unsigned_int = 4294967232; 
   process(unsigned_int);

   return 0;
}
