#include <stdio.h>

int main(void) {
   int x; 

   printf("EOF is %d\n", EOF);
   while(scanf("%d", &x) != EOF) {
      printf("%d\n", x);
   }

   printf("Bye\n");

   return 0;
}
