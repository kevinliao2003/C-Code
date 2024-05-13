#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_value(int x);
int *get_number(const char *str, int digits);

void print_value(int x) {
   printf("Value is %d\n", x);
}

/*
 * Returns an integer by extracting
 * digits from str. Caller must free
 * memory.
 */
int *get_number(const char *str, int digits) {
    int *answer = malloc(sizeof(int)); 
    char *new_str = malloc(digits + 1);  
    strncpy(new_str, str, digits); /* Does not add '\0' */
    new_str[digits] = '\0';
   
    *answer = atoi(new_str);
    free(new_str);

    return answer;
}

int main(void) {
   void (*print_value_func_ptr1)(int x);  /* Includes parameter name */
   void (*print_value_func_ptr2)(int);    /* Does not include parameter name */
   int *answer;
   int *(*get_number_func_ptr)(const char *str, int digits);
    
   print_value_func_ptr1 = print_value; /* Function pointer initialized */
   print_value_func_ptr1(150);
   print_value_func_ptr2 = print_value; /* Function pointer initialized */
   print_value_func_ptr2(250);

   get_number_func_ptr = get_number; /* Function pointer initialized */
   answer = get_number_func_ptr("759abc", 3); 
   print_value(*answer); /* answer dereferenced and printed out */
   free(answer); /* answer memory freed */
   
   return 0;
}
