/***********************************************/
/* This program creates a pipe between         */
/* the programs EngToSpa and SpaToFre          */
/* so we can translate from English to French. */
/* It is equivalent to executing on the        */
/* command line: EngToSpa | SpaToFre           */
/*                                             */
/* Notice that you need a total of three       */
/* processes (parent forks two children)       */
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

int main() {
   pid_t child_pid_one, child_pid_two;
   int pipe_fd[2]; /* pipe */

   /* Before the fork, we need to create the pipe */ 
   /* (otherwise no sharing of pipe) */
   if (pipe(pipe_fd) < 0) {
      err(EX_OSERR, "pipe error");
   }

   if ((child_pid_one = fork()) < 0) {
      err(EX_OSERR, "fork error");
   }

   if (child_pid_one == 0)  { /* CHILD #1's code (EngToSpa) */
      close(pipe_fd[0]); /* we don't need pipe's read end */

      /* Redirecting standard output to pipe write end */
      if (dup2(pipe_fd[1], STDOUT_FILENO) < 0) {
         err(EX_OSERR, "dup2 error");
      }
      /* Releasing resource */     
      close(pipe_fd[1]);
  
      /* execlp for EngToSpa */
      execlp("EngToSpa", "EngToSpa", NULL);
      err(EX_OSERR, "exec error");
   }  else { /* parent's code */
 
      /* Creating second child */
      if ((child_pid_two = fork()) < 0) {
         err(EX_OSERR, "fork error");
      } 

      if (child_pid_two == 0)  { /* CHILD #2's code (SpaToFre) */
         close(pipe_fd[1]); /* we don't need pipe's write end */

         /* Redirecting standard input to pipe read end */
         if (dup2(pipe_fd[0], STDIN_FILENO) < 0) {
            err(EX_OSERR, "dup2 error");
         }
         /* Releasing resource */
         close(pipe_fd[0]);

         /* execlp for SpaToFre */
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
