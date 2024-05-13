#include <stdio.h>

void print_value(int x);
void no_message_print(int x);
void deciding_which_function(int choice, void (**chosen_function)(int));

void print_value(int x) {
   printf("Value is %d\n", x);
}

void no_message_print(int x) {
   printf("%d\n", x);
}

/* chosen_function is a output parameter that allow
 * us to initialize a variable that is in the calling 
 * function to the function associated with
 * the specified choice. Notice the output parameter
 * is **, not *.
 */
void deciding_which_function(int choice, void (**chosen_function)(int)) {
   if (choice == 1) {
      *chosen_function = print_value;
   } else {
      *chosen_function = no_message_print;
   }
}

int main(void) {
   void (*print_function)(int);
   int value, function_choice;

   /* We are passing the address of the function pointer variable */
   printf("Enter integer value to print: ");
   scanf("%d", &value);

   printf("Enter which function (with message enter 1, without it 0): ");
   function_choice = 0; 
   scanf("%d", &function_choice);

   deciding_which_function(function_choice, &print_function);
   print_function(value); 
                                                                              
   return 0;
}
