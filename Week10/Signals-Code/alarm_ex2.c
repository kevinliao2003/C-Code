#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define COMMAND_LEN 255

static int seconds = 4; 

void sigalrm_handler(int sig) {
   printf("\nStill there? Inactive for %d seconds\n", seconds);
}

void alarm_example(void) {
   char command[COMMAND_LEN + 1] = "";

   /* Setting the alarm */
   signal(SIGALRM, sigalrm_handler);
   alarm(seconds);  

   while(1) {
      printf("shell: ");
      fflush(stdout);
      fgets(command, COMMAND_LEN + 1, stdin);
      if (command[0] != '\0') { 
         if(strcmp(command, "exit\n") == 0) {
            exit(0);
         } else {
            printf("processing command %s", command);
            command[0] = '\0'; /* Clears the command variable */
         }
      }
    
      /* Resetting (snooze?) the alarm */
      signal(SIGALRM, sigalrm_handler); /* Needed to restore handler */
      alarm(seconds);  
  }
}

int main(void)  {
   alarm_example(); 

   return 0;
}
