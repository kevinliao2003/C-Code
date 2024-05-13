#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/* Function that will handle SIGALRM signal */
void sigalrm_handler(int sig) {
   printf("hey, are you still there?\n");
   fflush(stdout);
}

void alarm_example(void) {
   int number_of_seconds = 2;

   signal(SIGALRM, sigalrm_handler);    /* Defining task for SIGALRM */
   alarm(number_of_seconds);    /* Scheduling SIGALRM for secs in the future */
   printf("Waiting for SIGALRM (alarm signal)\n");
   pause();                     /* Waits for signal */

   printf("Setting alarm again\n");
   /* We need to call signal again because after the first */
   /* SIGALRM received the default handler was restored    */
   signal(SIGALRM, sigalrm_handler); /* Defining task for SIGALRM */
   alarm(number_of_seconds);
   printf("Waiting for SIGALRM (alarm signal)\n");
   pause();
}

int main(void) {
   alarm_example();

   return 0;
}
