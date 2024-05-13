#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
   const char *str = "cmsc216 is great";
   char *p;
   int i;

   p = malloc(strlen(str) + 1); 
   strcpy(p, str);
   printf("Memory before free is: %s\n", p);
   printf("Memory before free in hexadecimal: "); 
   for (i = 0; i < 12; i++) {
      printf("%02x", p[i]);
   }
   printf("\n");

   free(p); 

   /* In the following code fragment 
      we are accessing memory that is 
      referred to by p after free. NEVER 
      do this. We are just trying to
      illustrate that whatever p points
      to have been changed by free
    */
  
   printf("Memory after free is: %s\n", p);
   printf("Memory after free in hexadecimal: "); 
   for (i = 0; i < 12; i++) {
      printf("%02x", p[i]);
   }
   printf("\n");

   return 0;
}
