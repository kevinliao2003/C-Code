#include <stdio.h>
#include <err.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sysexits.h>

#define MAX_LEN 80
static void error_check(int status, const char *error_message);
void print_powers(int limit);

int main() {
   char filename[MAX_LEN + 1] = "results.txt";
   int fd, status;

   /* Opening file for writing */
   status = fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
   error_check(status, "opening file");

   /* We need to print this message before dup2() otherwise */
   /* it will be sent to the file we opened */
   printf("Results can be found at %s\n", filename);

   /* Associating stdout with the opened file */
   status = dup2(fd, STDOUT_FILENO);
   error_check(status, "dup2");

   status = close(fd); /* Releasing resource */
   error_check(status, "closing file");

   /* When printf is used in print_powers */
   /* results will be sent to the file  */
   print_powers(10);

   exit(0);
}

static void error_check(int status, const char *error_message) {
   if (status < 0) {
      err(EX_OSERR, error_message);
   }
}

void print_powers(int limit) {
   int i = 0;

   for (i = 0; i <= limit; i++) {
      printf("%d\n", i * i);
   }
}

