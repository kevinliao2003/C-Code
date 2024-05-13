#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h> 
#include <string.h> 
#include <errno.h> 

/* 
   Note: Before running these examples, remove the files
   results.txt, results2.txt and errors_warnings.txt

   1. Try "a.out data.txt"
   2. Try "a.out" (You can indicate end of file with CTRL-D)
   3. Try  "a.out data.txt > results.txt"
   4. Try  "a.out data.txt >& results2.txt"
   5. Try "(a.out data.txt > results3.txt) >& errors_warnings.txt"
 */

#define MAX_LEN 80

int main(int argc, char *argv[]) {
   FILE *input; 
   char line[MAX_LEN + 1];
   
   /* Deciding where input will come from */
   if (argc == 1) {
      input = stdin;   /* standard input */
   } else if (argc == 2) { 
      /* Using file provided by the user */
      input = fopen(argv[1], "r");
      if (input == NULL) {
          fprintf(stderr, "File %s open failed. Error: %s\n", argv[1], strerror(errno));
          return EX_OSERR;   /* Notice error that is returned */
      }
   } else {
      fprintf(stderr, "Usage: a.out\n");
      fprintf(stderr, "Usage: a.out <filename>\n");
      return EX_USAGE;      /* Notice error that is returned */
   }

   /* Warning sent to stderr */
   fprintf(stderr, "Warning: About to process data\n");

   fgets(line, MAX_LEN + 1, input); /* reads a line */
   while (!feof(input)) {  /* checking for end of file */
      fputs(line, stdout); 

      fgets(line, MAX_LEN + 1, input); /* reads next line */
   }

   /* Closing the stream */
   fclose(input);

   printf("See you later\n");

   return EXIT_SUCCESS;
}
