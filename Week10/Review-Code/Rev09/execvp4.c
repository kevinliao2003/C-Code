#include <sys/wait.h>
#include <stdio.h>
#include <sysexits.h>
#include <err.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    const char * const argv[] = {"ls", "-F", NULL}; 
    pid_t pid;

    if ((pid = fork()) < 0) {
       err(EX_OSERR, "fork error");
    }
    if (pid) { /* parent code */
       wait(NULL); /* waiting for child to finish */
       printf("Parent pid = %d; my child had pid = %d\n", getpid(), pid);
    }
    else { /* child code */
       printf("PID %d replacing myself\n", getpid());
       execvp(argv[0], (char * const *)argv);
       err(EX_OSERR, "exec error");  /* why no if statement? */
    }

    return 0;
}
