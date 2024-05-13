#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <err.h>
#include <sysexits.h>

static void error_check(int status, const char *error_message);

/* The child sends an integer value to the parent using a pipe */

int main(void) {
   int pipe_fd[2];              /* Array to store pipe read/write ends */
   int number;
   pid_t child_pid;

   /* Creating pipe (needs to be created before fork) */
   /* otherwise the child will not get the pipe       */
   if (pipe(pipe_fd) < 0) {
      err(EX_OSERR, "pipe error");
   }

   if ((child_pid = fork()) < 0) {
      err(EX_OSERR, "fork error");
   }

   if (child_pid) {                      /* Parent code */
      int status;

      status = close(pipe_fd[1]);        /* Closing write end */
      error_check(status, "closing pipe");

      /* Waiting for data */
      read(pipe_fd[0], &number, sizeof(int));

      printf("Value received: %d\n", number);
      /* Why this will not work? write(STDOUT_FILENO, &number, sizeof(int)); */

      status = close(pipe_fd[0]);        /* Closing read end */
      error_check(status, "closing pipe");
      wait(NULL);                        /* Reaping */
   } else {                              /* Child code */
      int status;

      status = close(pipe_fd[0]);        /* Closing read end */
      error_check(status, "closing pipe");
      number = 1234;

      /* Sending data */
      write(pipe_fd[1], &number, sizeof(int));

      status = close(pipe_fd[1]);        /* Closing write end */
      error_check(status, "closing pipe");
   }

   return 0;
}

static void error_check(int status, const char *error_message) {
   if (status < 0) {
      err(EX_OSERR, error_message);
   }
}
