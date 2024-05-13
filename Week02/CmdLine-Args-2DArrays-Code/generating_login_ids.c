#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 80
#define MAX_LIST_LENGTH 50

void generate_id_list(char list[][MAX_LENGTH + 1], int number_of_ids);

void generate_id_list(char list[][MAX_LENGTH + 1], int number_of_ids) {
   int idx;

   for (idx = 0; idx < number_of_ids; idx++) {
      sprintf(list[idx], "cmsc%dumcp", idx + 1);
   }
}

int main() {
   int number_of_ids, idx;
   char list[MAX_LIST_LENGTH][MAX_LENGTH + 1];

   printf("Enter number of ids: ");    
   scanf("%d", &number_of_ids);  
   generate_id_list(list, number_of_ids);

   for (idx = 0; idx < number_of_ids; idx++) {
      printf("%s\n", list[idx]);
   }

   return 0;
}
