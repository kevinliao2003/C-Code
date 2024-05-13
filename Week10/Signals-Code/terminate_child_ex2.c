/***************************************************************/
/* SIGCHLD --> signal sent to parent process whenever a child  */
/*             terminates or stops                             */
/* SIGKILL --> terminates process and it cannot be ignored     */
/* SIGTERM --> terminates process. It can be blocked, handled  */
/*             and ignored                                     */
/*                                                             */
/***************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

int kill(pid_t pid, int sig);

void sigchld_handler(int signal_number) {
   printf("My child has terminated (parent pid %d)\n", getpid());
}

void terminate_example() {
   int answer, seconds = 2, status, signal_used;
   pid_t child_pid;

   printf("Parent Pid %d\n", getpid());
   signal(SIGCHLD, sigchld_handler); /* Defining handler called when */
                                     /* SIGCHLD received */
   child_pid = fork();
   if (child_pid) {             /* Parent code */
      printf
        ("Enter 0 to terminate using SIGKILL (otherwise using SIGTERM)\n");
      scanf("%d", &answer);

      if (answer == 0) {         /* Deciding signal to send */
         signal_used = SIGKILL;
      } else {
         signal_used = SIGTERM;
      }

      kill(child_pid, signal_used);     /* Sending signal to child */

      wait(&status);            /* Reaping */
      printf("Signal that caused child to terminate is: %d\n",
             WTERMSIG(status));
   } else {                     /* Child code */
      while (1) {
         printf("I am the child with id %d\n", getpid());

         sleep(seconds);
      }
   }
}

int main(void) {
   terminate_example();

   return 0;
}
