/*
 * 1. Experiment #1: Type "hello" and press enter.
 * 2. Experiment #2: Type "hello  bye" and press enter.
 *
 * Notice that we could have replaced the \n in the scanf
 * with a single space character.
 *
 */
#include <stdio.h>

#define MAX_LEN 80

int main() {
   char str[MAX_LEN + 1];

   scanf("%s\n", str);  /* In this example \n stands for 1 or more spaces. */
                        /* It gets in the way if you just want to read */
                        /* a single string. */
   printf("String read is \"%s\"\n", str);

   return 0;
}

