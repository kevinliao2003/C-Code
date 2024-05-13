#include <stdio.h>

/* 
  Example that illustrates how to recognize extra information
  on a line.  First just provide an integer then try an 
  integer and some information after.              
 */

#define MAX 80

int main(void) {
   char data[MAX + 1]; 

   printf("Provide an integer value (and nothing more): ");
   if (fgets(data, MAX + 1, stdin)) {
      char s1[MAX + 1];
      int x, values_read;

      values_read = sscanf(data, "%d%s", &x, s1);
      if (values_read == 2) {
         printf("You provided more data than needed.\n");
      } else {
         printf("Value provided is %d.\n", x); 
      }	        
   } else {
      printf("End of file seen.\n");
   }
   
   return 0;
}
