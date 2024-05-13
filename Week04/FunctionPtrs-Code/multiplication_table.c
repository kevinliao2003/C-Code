#include <stdio.h>

void print_decimal(unsigned int i) {
   printf("%3u ", i);
}

void print_hex(unsigned int i) {
   printf("%3x ", i);
}

/* 
 * print_function defines the output format for the value
 */
void print_table(void (*print_function)(unsigned int), 
                 int max_rows, int max_cols) {
   int row, col;
  
   for (row = 1; row <= max_rows; row++) {
      for (col = 1; col <= max_cols; col++) {
         print_function(row * col); 
         printf(" ");
      }
      printf("\n");
   }
}

int main(void) {
   int max_rows = 8, max_cols = 9, format;
   
   printf("Enter 1 for decimal, 2 for hex: ");
   scanf("%d", &format);
   if (format == 1) {
      /* Function pointer passed in as a parameter */
      print_table(print_decimal, max_rows, max_cols); 
   } else if (format == 2) {
      /* Function pointer passed in as a parameter */
      print_table(print_hex, max_rows, max_cols); 
   } else {
      printf("Invalid choice");
   }
 
   return 0;
}
