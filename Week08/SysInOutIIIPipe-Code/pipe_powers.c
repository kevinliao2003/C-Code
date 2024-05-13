#include <stdio.h>
#include <sys/wait.h>
#include <sysexits.h>
#include <err.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>

#define MAX_LEN 80

void print_powers();

void print_powers() {
   int i = 0, limit = 4;

   for (i = 0; i <= limit; i++) {
      printf("%d\n", i * i);
   }
}

/* To keep example simple we are assuming system calls */
/* are always successful, but for your projects you    */
/* need to check.                                      */
/* The parent reads a file name and sends it via a     */
/* a pipe to the child. The child reads the filename   */
/* opens the file and redirects the standard output to */
/* the opened file.  When print_powers() function is   */
/* called the output will be sent to the file.         */

int main(void) {
   pid_t child_pid;
   int pipe_fd[2];              /* For the pipe */
   char filename[MAX_LEN + 1];

   pipe(pipe_fd);               /* Creating the pipe */
   child_pid = fork();          /* Forking */

   if (child_pid) {             /* Parent code */
      close(pipe_fd[0]);        /* Closing pipe's read end */
      printf("Enter filename for results (e.g., results.txt): ");
      scanf("%s", filename);    /* Reading filename */

                                /* Sending filename */
      write(pipe_fd[1], filename, strlen(filename) + 1);
      close(pipe_fd[1]);        /* Closing pipe's write end */
      wait(NULL);               /* Reaping */
      printf("Results can be found in file %s\n", filename);
   } else {                     /* Child code */
      int fd;

      close(pipe_fd[1]);        /* Closing pipe's write end */
      read(pipe_fd[0], filename, MAX_LEN + 1);  /* Reading file name */
      close(pipe_fd[0]);        /* Closing pipe's read end */
      fd = open(filename, O_CREAT | O_WRONLY, 0666);
      dup2(fd, STDOUT_FILENO);  /* Redirecting */
      close(fd);                /* Releasing resource */

      print_powers();           /* Calling print_powers */
   }

   return 0;
}
