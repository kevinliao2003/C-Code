#include <stdio.h>
#include <string.h>

#define MAX 80

int main(void) {
   char word[MAX + 1];

   scanf("%s", word);
   if (!strcmp(word, "perro")) {
      printf("chien");
   } else if (!strcmp(word, "ave")) {
      printf("oiseaux");
   } else {
      printf("dontknow");
   }

   return 0;
}
