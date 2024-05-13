#include <stdio.h>

#define MAX_ROWS 20
#define MAX_COLS 30

/* Prototypes */
void print_array(int data[][MAX_COLS], int number_of_rows, 
                 int number_of_cols);
void double_array(int data[][MAX_COLS], int number_of_rows, 
                  int number_of_cols);
void print_one_dim_array(int data[], int length);
void print_array_two(int data[][MAX_COLS], int number_of_rows, 
                     int number_of_cols);

/* Function Definitions */
void print_array(int data[][MAX_COLS], int number_of_rows, 
                 int number_of_cols) {
   int row, col;

   for (row = 0; row < number_of_rows; row++) {
      for (col = 0; col < number_of_cols; col++) {
         printf("%d ", data[row][col]);
      } 
      printf("\n");
   }
}

/* As in one-dimensional arrays, changes to the */
/* array stick with the original array. */
void double_array(int data[][MAX_COLS], int number_of_rows, 
                  int number_of_cols) {
   int row, col;

   for (row = 0; row < number_of_rows; row++) {
      for (col = 0; col < number_of_cols; col++) {
          data[row][col] *= 2;
      } 
   }
}

void print_one_dim_array(int data[], int length) {
   int i;
   
   for (i = 0; i < length; i++) {
      printf("%d ", data[i]);
   } 
}

void print_array_two(int data[][MAX_COLS], int number_of_rows, 
                     int number_of_cols) {
   int row;

   for (row = 0; row < number_of_rows; row++) {
      print_one_dim_array(data[row], number_of_cols);
      printf("\n");
   }
}

int main() {
   int a[MAX_ROWS][MAX_COLS] = {{10, 20, 30},
                                {40, 50, 60}};
   int number_of_rows = 2, number_of_cols = 3;

   printf("Original array:\n");
   print_array(a, number_of_rows, number_of_cols);

   
   double_array(a, number_of_rows, number_of_cols);
   printf("After doubling array array:\n");
   print_array_two(a, number_of_rows, number_of_cols);

   return 0;
}
