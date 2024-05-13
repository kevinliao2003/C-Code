/***************************************************************/
/* SIGCHLD --> signal sent to parent process whenever a child  */
/*             terminates or stops.                            */
/* SIGINT --> signal sent by parent to terminate the child     */
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
   int answer, seconds = 3;
   pid_t child_pid;

   printf("Parent Pid %d\n", getpid());
   signal(SIGCHLD, sigchld_handler); /* Assigning the signal handler */
                                     /* To be called when SIGCHLD received */
   child_pid = fork();
   if (child_pid) {             /* Parent code */
      printf("To stop the child enter any number (and press enter)\n");
      scanf("%d", &answer);

      kill(child_pid, SIGINT);  /* Sending signal to child */
      wait(NULL);               /* Reaping */
   } else {                     /* Child code */
      while (1) {
         printf("I am the child with id %d\n", getpid());

         sleep(seconds);
      }
   }
}

int main(void) {
   terminate_example();

   return (0);
}
