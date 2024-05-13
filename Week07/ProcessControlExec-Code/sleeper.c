#include <stdio.h>
#include <unistd.h>
int main() {
   printf("\nList processes and look for process with pid = %d\n", getpid());
   execlp("sleep", "cmsc216program", "60", NULL);

   return 1; /* Why returning 1 instead of 0? */
}
