#include <stdio.h>

/****************************/
/* This function has a bug  */
/****************************/
int fact(int n) {
  if (n == 0 || n == 1) {
     return 1;
  } else {
     return n * fact(n);
  }
}

int main() {
   printf("fact(4) is %d\n", fact(4));

   return 0;
}
