#include <stdio.h>
#include <string.h>  /* String library */

void print_values(char param[]);

int main() {
   char name[] = "University of MD College Park";

   printf("Using strlen on name variable: %ld\n", strlen(name));
   printf("Using sizeof on name variable: %ld\n", sizeof(name));

   print_values(name);
   
   return 0;
}

void print_values(char param[]) {
   printf("In function print_values, using strlen: %ld\n", strlen(param));
   printf("In function print_values, using sizeof: %ld\n", sizeof(param));
}
