#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 80
#define MAX_LIST_LENGTH 50

void print_friends(char friends[][MAX_LENGTH + 1], 
                   int number_of_friends) {
   int i;

   for (i = 0; i < number_of_friends; i++) {
      printf("%10s\n", friends[i]); /* Printing in field width of 10 chars */
   }
}

int main() {
   char friends[MAX_LIST_LENGTH][MAX_LENGTH + 1];

   strcpy(friends[0], "Ross");
   strcpy(friends[1], "Joey");
   strcpy(friends[2], "Monica");
   print_friends(friends, 3);

   return 0;
}
