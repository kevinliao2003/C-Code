#include <stdio.h>
#include <string.h>

int main() {
   const char *t1 = "testudo";
   const char *t2 = "testudo";

   if (t1 != t2) {
      printf("Different memory areas\n");
   } else {
      printf("Same memory areas\n");
   }
   return 0;
}

