#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
   int status = 0;

   /* What does it mean for status to be set to 0 by wait? */
   /* For example wait(&status).                           */
   printf("WIFEXITED(status): %d\n", WIFEXITED(status));
   printf("WEXITSTATUS(status): %d\n", WEXITSTATUS(status));
   printf("WTERMSIG(status): %d\n", WTERMSIG(status));

   exit(0);
}
