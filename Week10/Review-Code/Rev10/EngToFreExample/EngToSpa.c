#include <stdio.h>
#include <string.h>

#define MAX 80

int main() {
   char word[MAX + 1];

   scanf("%s", word);
   if (!strcmp(word, "dog"))
       printf("perro");
   else if (!strcmp(word, "bird"))
       printf("ave");
   else 
       printf("dontknow");

   return 0;
}
