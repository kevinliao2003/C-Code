/***************************************************************/
/* SIGSTOP --> stops the process                               */
/* SIGCONT --> resumes a process execution                     */
/* SIGKILL --> terminates process and it cannot be ignored     */
/***************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

int kill(pid_t pid, int sig);

void start_stop_example() {
   int answer, seconds = 1, signal_to_use;
   pid_t child_pid;

   child_pid = fork();
   if (child_pid) {             /* Parent code */
      do {
         printf("I am the parent (pid %d)\n", getpid());
         printf
           ("Enter 1 (stop child), 2(resume child), 3 (terminate child)\n");
         fflush(stdout);
         scanf("%d", &answer);

         if (answer == 1) {
            signal_to_use = SIGSTOP;
         } else if (answer == 2) {
            signal_to_use = SIGCONT;
         } else {
            signal_to_use = SIGKILL;
         }

         kill(child_pid, signal_to_use);        /* Sending signal to child */

      } while (answer != 3);

     /* Reaping */
      wait(NULL);
   } else {                     /* Child code */
      int x = 1;

      while (1) {
         printf("I am the child (pid %d), x = %d\n", getpid(), x++);
         sleep(seconds);

         x %= 1000;
      }
   }
}

int main(void) {
   start_stop_example();

   return 0;
}
