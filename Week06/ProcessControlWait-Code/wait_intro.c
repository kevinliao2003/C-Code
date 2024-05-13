#include <stdio.h>
#include <sys/wait.h>
#include <sysexits.h> 
#include <err.h>
#include <unistd.h> 
#include <sys/types.h> 

int main() {
   pid_t pid, returned_value;
   

   if ((pid = fork()) < 0) { /* Forking */
      err(EX_OSERR, "fork error");
   }
   if (pid) { /* Parent code, pid != 0 */
      printf("Parent waiting for child\n");
      returned_value = wait(NULL);  /* Parent blocks (wait) until child exits; */
                                    /* Parent will reap the child */
                                
      printf("\nValue returned to parent by wait: %d\n", returned_value);
      printf("Parent pid = %d; the child had pid = %d\n", getpid(), pid);
   } else { /* Child code */
      printf("Child pid = %d; the parent has pid = %d\n", getpid(), getppid());
      printf("Child is starting to work, please wait about 4 seconds\n");
      sleep(4); /* Simulating child's processing, waiting 4 seconds */
      printf("Child has finished\n");
   }
   
   return 0;
}
