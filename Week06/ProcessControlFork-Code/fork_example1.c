#include <stdio.h>
#include <sysexits.h> 
#include <err.h> 
#include <unistd.h>     /* Required by fork() */  
#include <sys/types.h>  /* Required by pid_t */
#include <sys/wait.h>

int main() {
   pid_t result;       /* pid_t (integer value type) */

   printf("Hello\n");  /* Only printed by parent process */

   result = fork();    /* Creating child process */
   if (result < 0) {   /* Checking whether for was successful */
      err(EX_OSERR, "fork error"); /* Exiting if not successful */
   }

   /* Next message printed by both parent and child */
   /* End: Value returned by fork: 11014
      End: Value returned by fork: 0 */
   printf("End: Value returned by fork: %d\n", result);

   return 0;
}
