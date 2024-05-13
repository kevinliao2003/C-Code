#include <stdio.h>

int main(void) {
   printf("The name of this file is %s\n",__FILE__);
   printf("The name of this file is __FILE__\n");
   printf("Currently %s on %s\n",__TIME__, __DATE__);
   printf("This is line %d\n",__LINE__);

   if (__STDC__) {
      printf("Good ansi C\n");
   } else {
      printf("NOT Good ansi C\n");
   }
   printf("last line before return is %d\n",__LINE__); 

   return 0;
}
