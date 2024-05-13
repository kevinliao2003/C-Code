#include <stdio.h>
#include <unistd.h>

extern char **environ;
int main() {
   int idx;

   for (idx = 0; environ[idx] != NULL; idx++) { 
      printf("%s\n", environ[idx]);
   }

   return 0;
}

