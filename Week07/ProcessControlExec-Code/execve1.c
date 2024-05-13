#include <sys/wait.h>
#include <stdio.h>
#include <sysexits.h>
#include <err.h>
#include <unistd.h>
#include <sys/types.h>

extern char **environ;

int main() {
    const char * const argv[] = {"ls", "-F", NULL}; 
    pid_t pid;

    if ((pid = fork()) < 0) {  /* Forking */
       err(EX_OSERR, "fork error");
    }
    if (pid != 0) { /* Parent code */
       wait(NULL); /* Waiting for child to finish */
       printf("Parent pid = %d; my child had pid = %d\n", getpid(), pid);
    }
    else { /* Child code */
       printf("PID %d replacing child\n", getpid());
       execve("/bin/ls", (char * const *)argv, environ);
       err(EX_OSERR, "exec error");  
    }

    return 0;
}
