#include <stdio.h>
#include <stdlib.h>

/*
  This example shows how to extra information
  from a line ("parse a line") using sscanf.
  Also illustrates how to recognize an empty
  line using sscanf.
 */

#define MAX_FILENAME_LEN 20
#define MAX_STUDENTS_NAME_LEN 20
#define MAX_LINE_LEN (MAX_STUDENTS_NAME_LEN + 60)

int main(void) {
   FILE *input_stream;
   char filename[MAX_FILENAME_LEN + 1]; 
   char students_name[MAX_STUDENTS_NAME_LEN + 1], line[MAX_LINE_LEN + 1];
   int id;

   printf("Input file name (e.g., employee.txt): ");
   scanf("%s", filename);
   if (!(input_stream = fopen(filename, "r"))) {
      perror("error opening file");
      exit(EXIT_FAILURE);
   } else {
      int entries_read;
      while (fgets(line, MAX_LINE_LEN + 1, input_stream) != NULL) {
         entries_read = sscanf(line, "%s%d", students_name, &id);
         if (entries_read == EOF) {
            printf("Empty line recognized.\n");
         } else {
            printf("Name: %s, Id: %d\n", students_name, id);
         }
      } 
      fclose(input_stream);
      exit(EXIT_SUCCESS);
   }
}
