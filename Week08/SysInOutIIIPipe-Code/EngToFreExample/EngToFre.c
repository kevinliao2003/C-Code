/***********************************************/
/* This program creates a pipe between         */
/* the programs EngToSpa and SpaToFre          */
/* so we can translate from English to French. */
/* It is equivalent to executing on the        */
/* command line: EngToSpa | SpaToFre           */
/*                                             */
/* You need a total of three processes         */
/* (parent forks two children)                 */
/*                                             */
/* Although for this small example using only  */
/* two (parent and one child) process may work,*/
/* in other similar problems, a large data set */
/* will make such an approach invalid (it will */
/* not work).  Therefore use three processes.  */
/*                                             */
/* Translations available                      */
/*                                             */
/* English Spanish                             */
/* dog     perro                               */
/* bird    ave                                 */
/*                                             */
/* Spanish French                              */
/* perro   chien                               */
/* ave     oiseaux                             */
/***********************************************/

#include <sysexits.h>
#include <stdlib.h>
#include <err.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

/* To keep example simple we are assuming system calls */
/* are always successful, but for your projects you    */
/* need to check.                                      */

int main(void) {
   pid_t child_pid_one, child_pid_two;
   int pipe_fd[2];              /* Pipe */

   /* Before the fork, we need to create the pipe */
   /* (otherwise no sharing of pipe) */
   pipe(pipe_fd);
   child_pid_one = fork();      /* Forking */

   if (child_pid_one == 0) {    /* Childs #1's code (EngToSpa) */
      close(pipe_fd[0]);        /* we don't need pipe's read end */

      /* Redirecting standard output to pipe write end */
      dup2(pipe_fd[1], STDOUT_FILENO);
      close(pipe_fd[1]);        /* Closing write end */

      /* execlp for EngToSpa */
      execlp("EngToSpa", "EngToSpa", NULL);
      err(EX_OSERR, "exec error");
   } else {                     /* Parent's code */

      /* Creating second child */
      child_pid_two = fork();

      if (child_pid_two == 0) { /* Child #2's code (SpaToFre) */
         close(pipe_fd[1]);     /* We don't need pipe's write end */

         /* Redirecting standard input to pipe read end */
         dup2(pipe_fd[0], STDIN_FILENO);
         close(pipe_fd[0]);     /* Closing read end */

         /* execlp (loading/executing) SpaToFre */
         execlp("SpaToFre", "SpaToFre", NULL);
         err(EX_OSERR, "exec error");
      } else {
         /* Parent has no need for the pipe */
         close(pipe_fd[0]);
         close(pipe_fd[1]);

         /* Reaping each child */
         wait(NULL);
         wait(NULL);
      }
   }

   return 0;
}
