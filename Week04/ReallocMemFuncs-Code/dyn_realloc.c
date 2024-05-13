#include <stdio.h>
#include <stdlib.h>

/* 
 * Use output redirection for large input values.
 */

#define INITIAL_LENGTH 5

void print_array(const int *a, int length);

int main(void) {
  int *original_array = NULL, *bigger = NULL, idx;
  int new_length, seed = 10;

  /* Allocating space for array of an INITIAL_LENGTH size */
  /* Also checks if the memory allocation was successful */
  if (!(original_array = calloc(INITIAL_LENGTH, sizeof(int)))) {
     exit(EXIT_FAILURE);
  }

  /* Initializing array with random values and printing it */
  srand(seed);  /* Setting seed with srand() */
  for (idx = 0; idx < INITIAL_LENGTH; idx++) {
     original_array[idx] = rand() % 10;   /* Getting random value with rand() */
  }

  /* Printing array */
  print_array(original_array, INITIAL_LENGTH);

  /* Increasing length based on provided value */
  printf("Enter new length (e.g., 30, 10000, 1000000) (current value is %d): ", INITIAL_LENGTH);
  scanf("%d", &new_length);
  /* Reallocates memory to original_array, but this time with a BIGGER size */
  /* Assigns the new array to bigger */
  bigger = realloc(original_array, new_length * sizeof(int));
  /* Checks if the memory allocation was successful */
  if (bigger == NULL) {
     exit(EXIT_FAILURE);
  }

  /* New pointer is the SAME as the original one */
  if (bigger == original_array) {
     printf("New pointer SAME as original one\n");
  } else {
     printf("New pointer DIFFERENT than original one\n");
  }   

  /* Printing new array */
  /* All new_length values are printed out, but since they haven't
  been initialized, they are garbage values */
  print_array(bigger, new_length);

  /* Releasing memory */
  /* Only need to free 1 array, since the pointers are the same */
  free(bigger);

  return EXIT_SUCCESS;
}

void print_array(const int *a, int length) {
   int idx;

   printf("Array Values: ");
   for (idx = 0; idx < length; idx++) {
      printf("%d ", a[idx]);
   } 
   printf("\n");
}
