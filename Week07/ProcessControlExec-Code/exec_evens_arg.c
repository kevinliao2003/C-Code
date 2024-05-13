#include <sys/wait.h>
#include <stdio.h>
#include <sysexits.h>
#include <err.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
   pid_t pid;

   if ((pid = fork()) < 0) {  /* Forking */
      err(EX_OSERR, "fork error");
   }
   if (pid != 0) { /* Parent code */
      wait(NULL);  /* Assuming child finished succesfully */
   } else { /* Child code */
      printf("PID %d (child) will now execute execlp\n", getpid());

      /* Child wants to become the evens program with 20 as parameter */
      execlp("./evens", "evens", "20", NULL); 

      printf("Would this be ever printed?\n");
      err(EX_OSERR, "exec error");  /* Why no if statement? */
   }

   return 0;
}
