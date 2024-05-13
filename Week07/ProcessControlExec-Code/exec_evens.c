#include <stdio.h>
#include <sys/wait.h>
#include <sysexits.h>
#include <err.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
   pid_t child_pid;

   if ((child_pid = fork()) < 0) { /* Forking */
      err(EX_OSERR, "fork error");
   }
   if (child_pid != 0) { /* Parent code */
       int status;

       wait(&status);  /* Reaping and waiting for child */
       /* Can we write the following if expression in a shorter way? */
       if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
          printf("Child has finished successfully\n");
       }
   } else { /* Child code */
      printf("PID %d (child) will now execute execlp\n", getpid());

      /* Child process wants to become the evens program */
      execlp("./evens", "evens", NULL); 

      /* If execlp is successful we never get to this point as the */
      /* address space of thhe child was replaced with the evens program */
      printf("Would this be ever printed?\n");
      err(EX_OSERR, "exec error");  
   }

   return 0;
}
