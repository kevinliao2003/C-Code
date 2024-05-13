#include <stdio.h>
#include <string.h>
#include "text_manipulation.h"

/* Tests for an empty string */

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

   remove_spaces(" linguistics ", result, NULL);
   test_result = strcmp(result, "") == 0 && spaces_removed == 0;
   test_assert(test_result, "remove_spaces", 10);

   return 0;
}

