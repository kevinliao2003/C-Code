#include <stdio.h>
#include <stdlib.h> 

#define MAX_LEN 80

int main() {
   FILE *input; /* does not need to be named input */
   char line[MAX_LEN + 1] = "SOME VALUE HERE WRONG\n", filename[MAX_LEN + 1];   

   printf("Input file name (e.g., data.txt): ");
   scanf("%s", filename);
   if ((input = fopen(filename, "r")) == NULL) {
      perror("error opening file");
      exit(EXIT_FAILURE);
   } else {
      /* When we use feof we need to try to   */
      /* read first check for eof and process */
      /* Comment out next line to see problem */
      fgets(line, MAX_LEN + 1, input); 
      while (!feof(input)) {
         printf("%s", line);
         fgets(line, MAX_LEN + 1, input);
      } 
      fclose(input);
      exit(EXIT_SUCCESS);
   }
}
