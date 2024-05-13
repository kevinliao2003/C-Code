/*
Kevin Liao
Exercise #1 - Draw shapes using C fundamentals
*/

#include <stdio.h>

int draw_rectangle(int width, int length, char character); /* Prototype */
int draw_triangle(int size, char character); /* Prototype */
int valid_char(char character); /* Prototype */

int main() {
  int option = 0, width = 0, length = 0, size = 0; /* Shape dimensions */
  char character;

  do {
      printf("Enter 1(rectangle), 2(triangle), 3(other), 0(quit): ");
      scanf("%d", &option);

      if (option == 1) { /* Draws a rectangle */
	  printf("Enter character, width and length: ");
	  scanf(" %c %d %d", &character, &width, &length);
	  draw_rectangle(width, length, character);
      } else if (option == 2) { /* Draws a triangle */
	  printf("Enter character and size: ");
	  scanf(" %c %d", &character, &size);
	  draw_triangle(size, character);
      } else if (option != 1 && option != 2 && option != 3 && option != 0) {
	  printf("Invalid choice.\n");	/* User entered an invalid option */
      }
  } while (option != 0); /* User wants to quit playing */

  printf("Bye Bye.\n"); /* Program finishes */

  return 0;
}

/* Draws a rectangle based on the provided information */
int draw_rectangle(int width, int length, char character) {
  if (width <= 0 || length <= 0 || valid_char(character) == 0) { /* Invalid dimensions */
      printf("Invalid data provided.\n");
      return 0;
  } else { /* Valid dimensions */
      int row, col; /* current row and col */

      /* Prints the rectangle */
      for (row = 0; row < width; row++) {
	  for (col = 0; col < length; col++) {
	      printf("%c", character);
	  }
	  printf("\n");
      }

      return 1;
  }
}

/* Draws a triangle based on the provided information */
int draw_triangle(int size, char character) {
  if (size <= 0 || valid_char(character) == 0) { /* Invalid dimensions */
      printf("Invalid data provided.\n");
      return 0;
  } else { /* Valid dimensions */
      int start = size, end = size; /* start, end positions to print the char */
      int num_rows = size, num_cols = 2 * size - 1; /* number of rows and cols */
      int row, col; /* current row and col */

      /* Prints the triangle */
      for (row = 1; row <= num_rows; row++) {
	  for (col = 1; col <= num_cols; col++) {
	      if (col >= start && col <= end) {
		  printf("%c", character);
	      } else {
		  printf(" ");
              }
	  }
	  printf("\n");

	  start--;
	  end++;
      }

      return 1;
  }
}

/* Determines whether a char is valid */
int valid_char(char character) {
  if (character == '*' || character == '%' || character == '#') {
      return 1; /* Valid character */
  } else {
      return 0; /* Invalid character */
  }
}
