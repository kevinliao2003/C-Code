#include <sys/wait.h>
#include <stdio.h>
#include <sysexits.h>
#include <err.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    const char * const argv[] = {"ls", "-F", NULL}; 
    pid_t pid;

    if ((pid = fork()) < 0) { /* Forking */
       err(EX_OSERR, "fork error");
    }
    if (pid) { /* Parent code */
       wait(NULL); /* Waiting for child to finish */
       printf("Parent pid = %d; my child had pid = %d\n", getpid(), pid);
    }
    else { /* Child code */
       printf("PID %d replacing child\n", getpid());
       execvp(argv[0], (char * const *)argv);
       err(EX_OSERR, "exec error"); 
    }

    return 0;
}
