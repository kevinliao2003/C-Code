#include <stdio.h>
#include <stdlib.h> 

/* Try MAX_LEN value of 3 */
#define MAX_LEN 80

int main(void) {
   FILE *input; /* Does not need to be named input */
   char line[MAX_LEN + 1], filename[MAX_LEN + 1];   

   printf("Input file name (e.g., data.txt): ");
   scanf("%s", filename);
   if ((input = fopen(filename, "r")) == NULL) {
      perror("error opening file");
      exit(EXIT_FAILURE);
   } else {
      while (fgets(line, MAX_LEN + 1, input) != NULL) {
         printf("%s\n", line);
      } 
      fclose(input);
      exit(EXIT_SUCCESS);
   }
}
