#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <err.h>
#include <sysexits.h>

#define MAX_STR_LEN 80

/* To keep example simple we are assuming system calls */
/* are always successful, but for your projects you    */
/* need to check.                                      */
/* The program will read a number that will send to    */
/* the child using a pipe.  The child will then change */
/* its standard input to use the pipe end. Finally the */
/* child will execute exec to execute the "table"      */
/* program that prints square roots based on a value   */
/* read via scanf. Because the standard input has been */
/* changed, the value will come from the pipe end.     */

int main(void) {
   int pipe_fd[2];              /* pipe array */
   pid_t child_pid;
   char value[MAX_STR_LEN + 1];

   printf("Enter number to create sqr root's table using \"table\" program: ");
   /* Reading a string so we can provide a string */
   /* representing a number to the table program */

   fgets(value, MAX_STR_LEN + 1, stdin); 
   
   pipe(pipe_fd);               /* Creating the pipe */
   child_pid = fork();          /* Forking (done after pipe creation) */
   if (child_pid) {             /* Parent code */
      close(pipe_fd[0]);        /* Closing read end */
      write(pipe_fd[1], value, MAX_STR_LEN + 1);  /* Placing number in the pipe */
      close(pipe_fd[1]);        /* Closing write end */
      wait(NULL);               /* Reaping */
   } else {                     /* Child code */
      close(pipe_fd[1]);        /* Closing write end */

      dup2(pipe_fd[0], STDIN_FILENO); /* dup2 so input comes from the pipe */
      close(pipe_fd[0]);              /* Closing read end */ 
      execlp("./table", "table", NULL); /* Loading table program */
      err(EX_OSERR, "exec error");
   }

   return 0;
}
