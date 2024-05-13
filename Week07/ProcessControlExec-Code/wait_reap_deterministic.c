/**
 * The parent will wait for each child, in
 * the same order in which they were created.
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
   pid_t all_pids[MAX_CHILDREN], child_pid;
   int idx, status;
  
   /* Creating children processes */
   printf("\n**** Forking processes ****\n");
   for (idx = 0; idx < MAX_CHILDREN; idx++) {
      if ((all_pids[idx] = fork()) < 0) {
         err(EX_OSERR, "fork error while creating children");
      } 
      if (all_pids[idx] == 0) { /* Child code */
         printf("Child %d with pid %d created.\n", idx, getpid());
         sleep(rand() % 10); /* Simulates task child is completing */
	      exit(idx); /* IMPORTANT */
      } else { /* Parent code */
         printf("Parent (pid %d) created child %d.\n", getpid(), idx);
      }
   }

   printf("\n**** Reaping processes ****\n");
   idx = 0;
   while ((child_pid = waitpid(all_pids[idx++], &status, 0)) > 0) {
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
