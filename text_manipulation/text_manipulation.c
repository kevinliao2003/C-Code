#include <stdio.h>
#include <string.h>
#include "text_manipulation.h"

int remove_spaces(const char *source, char *result, int *num_spaces_removed) {
   /* if the source string is NULL or its length is 0 */
   if (source == NULL || (int) strlen(source) == 0) {
      return FAILURE;
   } else {
      /* start - position of first character
         end - position of last character 
				 spaces_removed - # of spaces removed*/
      int index, length = (int) strlen(source), start = 0, end = length - 1,
      spaces_removed = 0;

      /* determines the start position */
      for (index = 0; index < length; index++) {
         if (source[index] == ' ') {
            start++;
            spaces_removed = spaces_removed + 1;
         } else {
            break;
         }
      }

      /* determines the end position */
      for (index = length - 1; index >= 0; index--) {
         if (source[index] == ' ') {
            end--;
            spaces_removed = spaces_removed + 1;
         } else {
            break;
         }
      }

      /* builds the resulting string */
      for (index = start; index <= end; index++) {
         *result = source[index];
         result = result + 1;
      }
      /* adds a null character to the resulting string */
      result[index] = '\0';

      /* if num_spaces_removed is different from NULL,
         the integer associated with the parameter is set to the number of 
         spaces removed */
      if (num_spaces_removed != NULL) {
         *num_spaces_removed = spaces_removed;
      }

      return SUCCESS;
   }
}

int center(const char *source, int width, char *result) {
   /* if source is NULL, if source length is 0, 
      or if width is less than source length 
      OR if its length is larger than MAX_STR_LEN */
   if (source == NULL || (int) strlen(source) == 0 ||
       width < (int) strlen(source)) {
      return FAILURE;
   } else {
      /* start - start pos of source in resulting string
         end - end pos of source in resulting string
         num_blank - # of blank indexes
         source_index - current index of source
         result_index - current index of result */
      int length = (int) strlen(source), start = (width - length) / 2,
         source_index, result_index = 0;

      /* if width - strlen(source) is odd, the resulting string will have
         a smaller width by 1 */
      if ((width - length) % 2 == 1) {
         width--;
      }

      /* builds the resulting string */
      while (result_index < width) {
         /* creates the source string */
         if (result_index == start) {
            for (source_index = 0; source_index < length; source_index++) {
               *result = source[source_index];
               result = result + 1;
               result_index++;
            }
         } else {               /* creates blank spaces */
            *result = ' ';
            result = result + 1;
            result_index++;
         }
      }
      /* adds a null character to the resulting string */
      result[result_index] = '\0';

      return SUCCESS;
   }
}
