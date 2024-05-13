#include <stdio.h>
#include <sysexits.h> 
#include <err.h> 
#include <unistd.h>    /* Required by fork(), getpid, getppid */
#include <sys/types.h> /* Required by pid_t */
#include <sys/wait.h>  /* For wait */

int main() {
   int value = 10;
   pid_t process_id;

   printf("Parent process id of main process: %d\n", getppid());

   printf("Output:\n"); /* Notice that this message might be printed twice */
                        /* if you remove the \n. A \n or fflush(stdout)    */
                        /* flushes the buffer.                             */

   if ((process_id = fork()) < 0) {  /* Forking */
      err(EX_OSERR, "fork error");
   }

   if (process_id != 0) { /* Parent code */
      printf("Parent result: %d\n", value / 2);
      printf("Parent pid = %d; Child pid = %d\n", getpid(), process_id);
      /* wait blocks if child has not finished and reaps */
      /* By passing NULL we are specifying we are not checking what happened */
      wait(NULL);
   } else {  /* Child code */
      printf("Child result: %d\n", value * value);
      printf("Child pid = %d; My parent pid = %d\n", getpid(), getppid());
   }

   return 0;
}
