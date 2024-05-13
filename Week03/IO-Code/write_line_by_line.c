#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 80

int main(void) {
   FILE *input_stream, *output_stream;
   char src_filename[MAX_LEN + 1], target_filename[MAX_LEN + 1];
   char line[MAX_LEN + 1];   

   /* Input file */
   printf("Provide source file name: (e.g., data.txt): ");
   scanf("%s", src_filename);
   if ((input_stream = fopen(src_filename, "r")) == NULL) {
      perror("error opening file");
      exit(EXIT_FAILURE);
   }

   /* Output file */
   printf("Provide target file name: ");
   scanf("%s", target_filename);
   if ((output_stream = fopen(target_filename, "w")) == NULL) {
      perror("error opening file");
      exit(EXIT_FAILURE);
   }

   /* Copying data line by line */
   while (fgets(line, MAX_LEN + 1, input_stream) != NULL) {
      fputs(line, output_stream);
   }

   /* closing streams */
   fclose(input_stream);
   fclose(output_stream);

   printf("Copy (%s) of %s created\n", target_filename, src_filename);   

   return EXIT_SUCCESS;
}
