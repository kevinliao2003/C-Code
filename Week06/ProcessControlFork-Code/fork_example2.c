#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h> 
#include <err.h> 
#include <unistd.h>   
#include <sys/types.h>

int main() {
   pid_t result;
   int x = 20;
   char *p;

   printf("Hello\n");

   p = malloc(80);    /* Both the parent and child  */
                      /* have to free this memory. */

   result = fork();   /* Forking */
   if (result < 0) {  /* Checking for failure */
      err(EX_OSERR, "fork error");
   }

   if (result == 0) { /* Executed by only child */
      printf("I am the child (increases x) %d\n", ++x);
      /* Both parent and child print the same address */
      printf("Value of address in child %p\n", (void *)p);
   } else { /* Executed by only parent */
      printf("I am the parent (decreases x) %d\n", --x);
      /* Both parent and child print the same address */
      printf("Value of address in parent %p\n", (void *)p);
   }
   /* The addresses for the child and parent are the same */

   free(p);  /* Both parent cand child must free */

   printf("Done\n");

   return 0;
}
