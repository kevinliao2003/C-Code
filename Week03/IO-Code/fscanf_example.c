#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LEN 20
#define MAX_STUDENTS_NAME_LEN 20

int main(void) {
   FILE *input_stream;
   char filename[MAX_FILENAME_LEN + 1]; 
   char students_name[MAX_STUDENTS_NAME_LEN + 1];   
   int id;

   printf("Input file name (e.g., employee.txt): ");
   scanf("%s", filename);
   if (!(input_stream = fopen(filename, "r"))) {
      perror("error opening file");
      exit(EXIT_FAILURE);
   } else {
      while (fscanf(input_stream, "%s%d", students_name, &id) != EOF) {
         printf("Name: %s, Id: %d\n", students_name, id);
      } 
      fclose(input_stream);
      exit(EXIT_SUCCESS);
   }
}
