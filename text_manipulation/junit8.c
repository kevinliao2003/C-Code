#include <stdio.h>
#include <string.h>
#include "text_manipulation.h"

/******************************************************** 
 * Prints a pass or fail message for the specified test.* 
 ********************************************************/
void test_assert(int test_result, const char *test_name, int test_number) {
   if (test_result)  {
      printf("pass %s %d\n", test_name, test_number);
   } else {
      printf("fail %s %d\n", test_name, test_number);
   }
}

int main() {
   char result[MAX_STR_LEN + 1]; 
   int spaces_removed, test_result;

   remove_spaces("  computer   science          ", result, &spaces_removed);
   test_result = strcmp(result, "computer   science") == 0 && spaces_removed == 12;
   test_assert(test_result, "remove_spaces", 8);

   return 0;
}
