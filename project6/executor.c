/*
Kevin Liao
117815542
kliao
*/

#include <stdio.h>
#include <unistd.h> /* Required by fork() */
#include <sys/types.h> /* Required by pid_t */
#include <err.h>
#include <string.h>
#include <sysexits.h>
#include <sys/wait.h> /* Required by wait() */
#include <fcntl.h> /* Required by open() */
#include <stdlib.h> /* Required by exit */
#include "command.h"
#include "executor.h"

#define OPEN_FLAGS (O_WRONLY | O_TRUNC | O_CREAT)
#define DEF_MODE 0664

/* NOTES:
- For the SUBSHELL, child must exit, because exit returns a shell.
If exit is NOT returned, the program would continue running.
*/

/*static void print_tree(struct tree *t);*/
static int execute_aux(struct tree *t, int p_input_fd, int p_output_fd);

int execute(struct tree *t) {
   return execute_aux(t, STDIN_FILENO, STDOUT_FILENO);
}

static int execute_aux(struct tree *t, int p_input_fd, int p_output_fd) {
   if (t->conjunction == NONE) {
      if (!strcmp(t->argv[0], "exit")) { /* terminates program */
         exit(0);
      } else if (!strcmp(t->argv[0], "cd")) { /* changes directory */
         if (t->argv[1] == NULL) { /* if given no arguments */
            if (chdir(getenv("HOME")) < 0) { /* changes to home directory */
               perror(getenv("HOME"));
            }
         } else if (chdir(t->argv[1]) < 0) {
            perror(t->argv[1]);
         }
      } else { /* other commands */
         pid_t pid; /* pid_t (integer value type) */
         int input_fd = 0, output_fd = 0;
         int status;

         pid = fork();
         if (pid < 0) { /* FORK FAILURE */
            perror("FORK FAILED\n");
            exit(EX_OSERR);
         } else if (pid == 0) { /* Child code */
            /* determines the input file descriptor */
            if (t->input != NULL) {
               input_fd = open(t->input, O_RDONLY);
               if (input_fd < 0) { /* OPEN FAILURE */
                  perror("OPEN FAILED\n");
                  exit(EX_OSERR);
               }

               /* maps file descriptor 0 to file that will be used for input */
               if (dup2(input_fd, STDIN_FILENO) < 0) { /* DUP2 FAILURE */
                  perror("DUP2 FAILED\n");
                  exit(EX_OSERR);
               }
               if (close(input_fd) < 0) { /* CLOSE FAILURE */
                  perror("CLOSE FAILED\n");
                  exit(EX_OSERR);
               }
            } else {
               input_fd = p_input_fd;
            }

            /* determines the output file descriptor */
            if (t->output != NULL) {
               output_fd = open(t->output, OPEN_FLAGS, DEF_MODE);
               if (output_fd < 0) { /* OPEN FAILURE */
                  perror("OPEN FAILED\n");
                  exit(EX_OSERR);
               }

               /* maps file descriptor 1 to file that will be used for output */
               if (dup2(output_fd, STDOUT_FILENO) < 0) { /* DUP2 FAILURE */
                  perror("DUP2 FAILED\n");
                  exit(EX_OSERR);
               }
               if (close(output_fd) < 0) {
                  perror("CLOSE FAILED\n");
                  exit(EX_OSERR);
               }
            } else {
               output_fd = p_output_fd;
            }

            /* executes command */
            if (execvp(t->argv[0], (char * const *)t->argv) < 0) { /* INVALID */
               fprintf(stderr, "Failed to execute %s\n", t->argv[0]);
               fflush(stdout);
               exit(EX_OSERR);
            } else {
               return 0;
            }  
         } else { /* Parent code */
            wait(&status); /* terminates the child */
            return status;
         }
      }
   } else if (t->conjunction == AND) {
      /* status value returned by processing left subtree */
      int left_status = execute_aux(t->left, p_input_fd, p_output_fd);
      if (left_status == 0) { /* left tree execution is successful */
         return execute_aux(t->right, p_input_fd, p_output_fd);
      } else {
         return left_status;
      }
   } else if (t->conjunction == OR) {

   } else if (t->conjunction == SEMI) {
      
   } else if (t->conjunction == PIPE) {
      /* the standard output to the left of the pipe character 
      connects to the standard input to the right of the pipe character */
      pid_t pid_first;
      int pipe_fd[2]; /* Pipe */
      /* input_fd - input file descriptor, 
         output_fd - output file descriptor */
      int input_fd = 0, output_fd = 0;

      /* checks for ambiguous output */
      if (t->left->output != NULL) {
         printf("Ambiguous output redirect.\n");
         return 1; /* FAILURE*/
      }

      /* checks for ambiguous input */
      if (t->right->input != NULL) {
         printf("Ambiguous input redirect.\n");
         return 1; /* FAILURE */
      }

      /* Creates the pipe */
      if (pipe(pipe_fd) < 0) { /* PIPE FAILURE */
         perror("PIPE FAILED\n");
         exit(EX_OSERR);
      }

      pid_first = fork(); /* Forking */
      if (pid_first < 0) { /* FORK FAILURE */
         perror("FORK FAILED\n");
         exit(EX_OSERR);
      } else if (pid_first == 0) { /* left subtree */
         /* Opens the file and uses t->input as input file 
         descriptor for the left subtree */
         if (t->input != NULL) {
            input_fd = open(t->input, O_RDONLY);
            if (input_fd < 0) { /* OPEN FAILURE */
               perror("OPEN FAILED\n");
               exit(EX_OSERR);
            }
         } else { /* if t->input is NOT defined */
            input_fd = p_input_fd;
         }

         /* closes the pipe's read end */
         if (close(pipe_fd[0]) < 0) { /* CLOSE FAILURE */
            perror("CLOSE FAILED\n");
            exit(EX_OSERR);
         }

         /* output file descriptor as the write end of the pipe */
         if (dup2(pipe_fd[1], STDOUT_FILENO) < 0) {
            perror("DUP2 FAILED\n");
            exit(EX_OSERR);
         }

         /* closes the pipe's write end */
         if (close(pipe_fd[1]) < 0) { /* CLOSE FAILURE */
            perror("CLOSE FAILED\n");
            exit(EX_OSERR);
         } 

         /* Recursive call */
         return execute_aux(t->left, input_fd, p_output_fd);
      } else { /* right subtree */
         /* Opens the file and uses t->output as output file 
         descriptor for the right subtree */
         if (t->output != NULL) {
            output_fd = open(t->output, OPEN_FLAGS, DEF_MODE);
            if (output_fd < 0) { /* OPEN FAILURE */
               perror("OPEN FAILED\n");
               exit(EX_OSERR);
            }
         } else { /* if t->output is NOT defined */
            output_fd = p_output_fd;
         }

         /* closes the pipe's write end */
         if (close(pipe_fd[1]) < 0) { /* CLOSE FAILURE */
            perror("CLOSE FAILED\n");
            exit(EX_OSERR);
         }

         /* input file descriptor as the read end of the pipe */
         if (dup2(pipe_fd[0], STDIN_FILENO) < 0) {
            perror("DUP2 FAILED\n");
            exit(EX_OSERR);
         }

         /* closes the pipe's read end */
         if (close(pipe_fd[0]) < 0) { /* CLOSE FAILURE */
            perror("CLOSE FAILED\n");
            exit(EX_OSERR);
         }

         wait(NULL); /* terminates the child */

         /* Recursive call */
         return execute_aux(t->right, p_input_fd, output_fd);
      }
   } else { /* SUBSHELL */
      pid_t pid;
      int input_fd, output_fd;
      /* status value of processing left subtree */
      int left_status;

      if (t->input != NULL) {
         input_fd = open(t->input, O_RDONLY);
         if (input_fd < 0) { /* OPEN FAILURE */
            perror("OPEN FAILED\n");
            exit(EX_OSERR);
         } 
      } else {
         input_fd = p_input_fd;
      }

      if (t->output != NULL) {
         output_fd = open(t->output, OPEN_FLAGS, DEF_MODE);
         if (output_fd < 0) { /* OPEN FAILURE */
            perror("OPEN FAILED\n");
            exit(EX_OSERR);
         } 
      } else {
         output_fd = p_output_fd;
      }

      pid = fork();
      if (pid < 0) { /* FORK FAILURE */
         perror("FORK FAILED\n");
         exit(EX_OSERR);
      } else if (pid == 0) { /* Child code */
         /* Recursive call */
         left_status = execute_aux(t->left, input_fd, output_fd);
         /* returns the status of processing the left subtree */
         exit(left_status);
      } else { /* Parent code */
         wait(NULL); /* terminates child */
      }
   }

   /*print_tree(t);*/  

   return 0; /* SUCCESS */
}


/*static void print_tree(struct tree *t) {
   if (t != NULL) {
      print_tree(t->left);

      if (t->conjunction == NONE) {
         printf("NONE: %s, ", t->argv[0]);
      } else {
         printf("%s, ", conj[t->conjunction]);
      }
      printf("IR: %s, ", t->input);
      printf("OR: %s\n", t->output);

      print_tree(t->right);
   }
}*/