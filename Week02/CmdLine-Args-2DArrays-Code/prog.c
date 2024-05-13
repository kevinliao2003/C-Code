#include <stdio.h>

/* Examples to run   */
/* 1: a.out          */
/* 2: a.out 10 20    */
/* 3: ./a.out 10 20  */
/* 4. rename a.out   */
int main(int argc, char *argv[]) {
   int idx;

   printf("Argc value is: %d\n", argc);
   for (idx = 0; idx < argc; idx++) {
      printf("Arg #%d: %s\n", idx, argv[idx]);
   }

   if (argv[argc] == NULL) {
      printf("Last array entry is null\n");
   }

   return 0;
}
