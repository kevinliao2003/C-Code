/*
 * If a process ends before its child, init (pid 1) will reap the child. If 
 * the process does not end, but the child does, the process needs to reap 
 * the * child, otherwise it will become a zombie.  

 * A shell is a process that runs for a long long time so at some point 
 * it needs to reap any process that it has created, otherwise the process
 * table will be exhausted.
 *
 * If a shell is NOT supporting background processing (e.g., a.out &) then
 * the usual wait/waitpid can reap a particular process.  If the shell provides 
 * background processing, it needs to reap without stopping. For this scenario, 
 * the shell can reap using the following loop  (NOTICE THE SEMICOLON):
 *
 *         while (waitpid(-1, NULL, WNOHANG) > 0); 
 *
 * The shell will not stop (WNOHANG) if there is nothing to reap, otherwise it 
 * reaps any process that has finished.  The shell executes the above loop 
 * every so often to make sure zombies are reaped.
 *
 * In the example below, the parent (represents the shell) forks a process that 
 * sleeps for particular number of seconds (simulates a task to be performed in 
 * the background).  Notice the shell does not perform a wait that blocks the 
 * shell.  The parent proceeds to ask the user for a number to compute a square.  
 * After the child process has finished (done message) and before you input a 
 * number, you will see there is a zombie process ([reapingForShell] <defunct>) 
 * in the process * listing shown by "ps -fu yourUserId".  If you enter a number 
 * to compute square, the zombie is gone.
 *
 * To run this example:
 * % a.out
 *
 * In separate command window run "ps -fu yourUserId" until you see the zombie 
 * ([reapingForShell] <defunct>).  At this point, return to the * first window 
 * and enter a number to compute square. Go to the second window and run 
 * "ps -fu yourUserId" again (no more zombie)
 * 
 * Note: CTRL-C to stop main program (shell)
 *
 */
 
#include <sys/wait.h>
#include <sysexits.h>
#include <stdlib.h>
#include <err.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(void) {
   pid_t pid;

   if ((pid = fork()) < 0) { /* Forking */
      err(EX_OSERR, "fork error");
   }

   if (pid == 0) { /* Child */
      sleep(10); /* Simulates child's task */
      exit (0);
   }  else { /* Parent */
      printf("\nParent (pid=%d) created child (pid=%d)\n", getpid(), pid);
      /* The following loop will never end (similar to a shell) */
      /* It will read a value and compute the square */
      do {
         int x;
         /* Next loop checks whether something can be reaped. If */
         /* nothing can be reaped, we continue (WNOHANG). What */
         /* happens if we remove the loop? zombie process! */

         printf("*** Parent is checking if there is any process to reap ***\n");
         while (waitpid(-1, NULL, WNOHANG) > 0);   /* Reaper */

         /* Shell is asking value from user to compute square */
         printf("\nInput integer value to compute square (or CTRL-C to end): ");
         scanf("%d", &x);
         printf("Square of %d is %d\n", x, x * x);

      } while(1);  /* Infinite loop */
   }
}
