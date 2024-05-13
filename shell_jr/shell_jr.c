#include <stdio.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h> /* Required by fork() */
#include <sys/types.h> /* Required by pid_t */
#include <err.h>
#include <stdlib.h> /* Required by exit */
#include <sys/wait.h> /* Required by wait() */

int main() {
    FILE *input = stdin;
    /* maximum of 1024 characters for a line of input */
    char line[1025] = "", command[1025] = "";
    int status;
    
    printf("shell_jr: ");
    fflush(stdout);
    while (fgets(line, 1025, input) != NULL) {
        /* user inputs a command */
        sscanf(line, "%s", command);

        if (!strcmp(command, "exit")) { /* program is terminated */
            printf("See you\n");
            exit(0);
        } else if (!strcmp(command, "hastalavista")) { /* program is terminated */
            printf("See you\n");
            exit(0);
        } else if (!strcmp(command, "cd")) { /* changes the working directory */
            /* user provides a directory as an argument */
            char directory[1025] = "";
            sscanf(line, "%s %s", command, directory);
            if (chdir(directory) == -1) { /* INVALID DIRECTORY */
                printf("Cannot change to directory %s\n", directory);
                fflush(stdout); /* flushes the output buffer */
            }
        } else { /* ALL OTHER COMMANDS */
            char arg2[1025] = "";
            pid_t result; /* pid_t (integer value type) */

            sscanf(line, "%s %s", command, arg2);

            if ((result = fork()) < 0) { /* Forking */
                err(EX_OSERR, "fork error");
            } else if (result == 0) { /* Child executing command */
                /* command arguments */
                char* argv[3];
                argv[0] = command;
                argv[1] = arg2;

                if (execvp(argv[0], (char * const *)argv) < 0) { /* INVALID COMMAND */
                    printf("Failed to execute %s\n", command);
                    exit(EX_OSERR);
                }
            } else { /* Reaping */
                wait(&status);
            }
        }

        printf("shell_jr: ");
        fflush(stdout); /* flushes the output buffer */
    }

    exit(0);
}
