/*
 * 1. Do not confuse the exit status (value returned from
 *    the program using exit or return from main) with
 *    the value that is initialized by wait (e.g., wait(&status)).
 *    The status integer has the exit status and additional
 *    information.  We use the macros WIFEXITED(status), 
 *    WEXITSTATUS(status), and WTERMSIG(status) to retrieve
 *    that information.
 * 
 * 2. WIFEXITED(status) - true if the program terminated
 *    normally via exit or return from main.  Two examples
 *    of when a program does not terminate normally: when
 *    a segmentation fault takes place or if the program is
 *    terminated via a signal (e.g., kill <process_id>).   
 *
 * 3. Remember that in linux, a program indicates it completed
 *    the expected task by returning 0 (e.g., exit(0)).
 *
 * 4. You can list signals by using kill -l
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sysexits.h> 
#include <err.h> 
#include <unistd.h>    /* Required by fork(), getpid, getppid */
#include <sys/types.h> /* Required by pid_t */

int main() {
   pid_t process_id;

   if ((process_id = fork()) < 0) { /* Forking */
      err(EX_OSERR, "fork error");
   } 

   if (process_id != 0) { /* Parent code */
      int status;  

      wait(&status); /* Waiting an reaping */
      if (WIFEXITED(status)) {
         printf("Child finished normally (via exit or return in main)\n");
	 if (WEXITSTATUS(status) == 0) {
            printf("Child completed the task successfully (e.g., exit(0))\n");    
	 } else {
            printf("Child did NOT complete the task successfully (e.g., exit(FAILURE))\n");    
	 }
      } else {
         printf("Child did NOT finish normally (exit or return in main); signal must have occured\n");
         printf("REPORT:\n");
	 printf("WIFEXITED(status): %d\n", WIFEXITED(status));
	 printf("WEXITSTATUS(status): %d\n", WEXITSTATUS(status));
	 printf("WTERMSIG(status) - (signal caused child to terminate): %d\n", WTERMSIG(status));
      }

      exit(0); /* Parent exit */

   } else {  /* Child code */
      int value;

      printf("\nEnter case 1: child finishes normally and completed task\n");
      printf("Enter case 2: child finishes normally but did not complete task\n");
      printf("Enter case 3: child generates segfault\n");
      printf("Or instead of entering a number ");
      printf("kill the child process (kill %d)\n\n", getpid());
      printf("Enter your choice (1, 2, 3, or signal): ");
      scanf("%d", &value);
      if (value == 1) {  
         int x;

         printf("Enter positive integer: ");
         scanf("%d", &x);
         printf("Squared value is %d\n", x * x);
         exit(EXIT_SUCCESS); /* Returning 0 to indicate success */
      } else if (value == 2){
         int x = 3;

         if (x % 2 == 0) {
            printf("The cube of %d is %d\n", x, x * x * x);
            exit(EXIT_SUCCESS); /* Returning 0 to indicate success */
         } else {
            printf("Invalid value provided: expected even\n");
            exit(40); /* Returning a value other than 0; 40 was selected randomly */
         }
      } else if (value == 3) {
         char *p = NULL;
         *p = 20;
         exit(EXIT_FAILURE);
      } else {
         printf("Invalid choice\n");
         exit(EXIT_FAILURE);
      }
   }
}

