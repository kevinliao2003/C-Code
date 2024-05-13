#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <err.h>
#include <sysexits.h>
#include <string.h>

#define MAX_LEN 80

/* To keep example simple we are assuming system calls */
/* are always successful, but for your projects you    */
/* need to check.                                      */
/* Child sends the parent a string that the parent     */
/* displays.                                           */

int main(void) {
   int pipe_fd[2];              /* Pipe array */
   char sandwich[MAX_LEN];      /* Not using +1 as we are */
                                /* not treating it as string */
   pid_t child_pid;

   pipe(pipe_fd);               /* Creating pipe */
   child_pid = fork();          /* Forking */

   if (child_pid) {             /* Parent code (eats the sandwich) */
      ssize_t bytes_read;

      close(pipe_fd[1]);        /* Closing write end */
      bytes_read = read(pipe_fd[0], sandwich, MAX_LEN);

      write(STDOUT_FILENO, sandwich, bytes_read);
      close(pipe_fd[0]);        /* Closing read end */

      wait(NULL);               /* Reaping */
   } else {                     /* Child code (prepares the sandwich) */
      const char *bread_cheese_sandwich = "BreadCheeseBread";
      close(pipe_fd[0]);        /* Closing read end */

      write(pipe_fd[1], bread_cheese_sandwich, strlen(bread_cheese_sandwich));
      close(pipe_fd[1]);        /* Closing write end */
   }

   return 0;
}
