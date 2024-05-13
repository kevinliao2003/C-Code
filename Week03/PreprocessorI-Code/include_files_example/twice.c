/*
   This code does not compile; it
   shows the error message we see
   when the same structure is defined
   twice.
 */

#include <stdio.h>

typedef struct {
   int x, y;
} My_point;

typedef struct {
   int x, y;
} My_point;

int main(void) {
   return 0;
}
