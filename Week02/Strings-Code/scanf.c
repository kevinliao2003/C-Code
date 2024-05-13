#include <stdio.h>

#define MAX_LEN 80

int main() {
   char first_name[MAX_LEN + 1], last_name[MAX_LEN + 1], tmp;

   printf("Enter your first name: ");
   scanf("%s", first_name);  
   printf("First name provided is \"%s\"\n", first_name);
    
   printf("Enter your last name: ");
   scanf("%s", last_name);  
   printf("Last name provided is \"%s\"\n", last_name); 

   scanf("%c", &tmp);   /* Why could we find a newline? */
   if (tmp == '\n') {
      printf("Newline detected\n");
   }

   return 0;
}
