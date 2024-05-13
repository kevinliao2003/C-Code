/*
 * The parent will wait for each child, but
 * the order in which the output will appear
 * is non-deterministic. 

 * Reaping children in no particular order. 
 * pid = -1 parameter below defines wait set to
 * be all parent's processes. options = 0
 * makes waitpid suspend execution of calling 
 * process until a child in wait set terminates
 * pid != -1 defines the wait set to be the child
 * process with the specified pid 
 *
 * After all children have been reaped, next call to 
 * waitpid returns -1 and sets errno to ECHILD 
 *
 * Initially try 2 as MAX_CHILDREN.  To see output
 * different order in reaping try 12 as MAX_CHILDREN
 *
*/

#include <stdio.h>
#include <sys/wait.h>
#include <sysexits.h>
#include <stdlib.h>
#include <err.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

#define MAX_CHILDREN  12

int main() {
   pid_t child_pid, pid;
   int idx, status;
  
   /* Creating children processes */
   printf("\n**** Forking processes ****\n");
   for (idx = 0; idx < MAX_CHILDREN; idx++) {
      if ((pid = fork()) < 0) {
         err(EX_OSERR, "fork error while creating children");
      } 
      if (pid == 0) { /* Child code */
         printf("Child %d with pid %d created.\n", idx, getpid());
         sleep(rand() % 10); /* Simulates task child is completing */
	      exit(idx); /* IMPORTANT */
      } else { /* Parent code */
         printf("Parent (pid %d) created child %d.\n", getpid(), idx);
      }
   }

   sleep(2); /* Giving children a chance to finish printing created messages */
   printf("\n**** Reaping processes ****\n");
   while ((child_pid = waitpid(-1, &status, 0)) > 0) { /* notice -1 */
      if (WIFEXITED(status)) {
         printf("Child (pid %d) finished (exit status %d).\n", child_pid, WEXITSTATUS(status));
      } else {
         printf("Child (pid %d) terminated abnormally.\n", child_pid);
      }
   }
   printf("**** Done reaping processes ****\n\n");

   /* After all children have been reaped, next call to waitpid */
   /* returns -1 and sets errno to ECHILD */
   if (errno != ECHILD) { /* If false all children have been reaped */
      perror("waitpid error"); 
      exit(EXIT_FAILURE);
   } else { 
      printf("Reaping completed\n");
      exit(EXIT_SUCCESS);
   }
}
