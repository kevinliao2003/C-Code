#include <stdio.h>
#include <string.h>
#include "document.h"

int main() {
   Document doc;
   const char *doc_name = "Quiz Description";
   int paragraph_number, line_number, number_of_lines;

   init_document(&doc, doc_name);

   /* Adding paragraph */
   paragraph_number = 0;
   add_paragraph_after(&doc, paragraph_number);

   /* Adding lines to paragraph */
   paragraph_number = 1;

   /* First line */
   line_number = 0;
   add_line_after(&doc, paragraph_number, line_number, "quiz Information is:");

   /* Additional lines */
   add_line_after(&doc, paragraph_number, 1, "the quiz will");
   add_line_after(&doc, paragraph_number, 2, "cover topics discussed in lecture.");
   add_line_after(&doc, paragraph_number, 2, "only");
   add_line_after(&doc, paragraph_number, 4, "We will be quized on the material");
   add_line_after(&doc, paragraph_number, 5, "and the pointers and the memory diagrams");
   
   /* Additional paragraphs and lines */
   add_paragraph_after(&doc, 1);
   add_line_after(&doc, 2, 0, "My information:");
   add_line_after(&doc, 2, 1, "I am Kevin Liao");
   add_line_after(&doc, 2, 2, "I am 19 years old:");
   add_line_after(&doc, 2, 3, "I study computer science");
   add_line_after(&doc, 2, 4, "I am into linguistics");
   remove_line(&doc, 2, 3); /* "I am 19 years old" removed */
   replace_text(&doc, "a", "hell");
   highlight_text(&doc, "hell");
   remove_text(&doc, "hell");

   /* Additional paragraphs and lines */
   append_line(&doc, 2, "I think programming is interesting");

   add_paragraph_after(&doc, 2);
   add_line_after(&doc, 3, 0, "Russian is a Slavic language");
   add_line_after(&doc, 3, 1, "German is a Germanic language");
   add_line_after(&doc, 3, 2, "Java is an object oriented programming language");
   add_line_after(&doc, 3, 3, "Spanish is a Romance language");

   add_paragraph_after(&doc, 3);
   add_line_after(&doc, 4, 0, "There are pointers in C");
   add_line_after(&doc, 4, 1, "We have to allocate memory ourselves in C");

   print_document(&doc);

   printf("%d\n", add_paragraph_after(&doc, 6)); /* FAILURE */
   printf("%d\n", add_line_after(&doc, 6, 3, "Science")); /* FAILURE */
   printf("%d\n", remove_line(&doc, 3, 6)); /* FAILURE */
   printf("%d\n", remove_line(&doc, 5, 1)); /* FAILURE */
   printf("%d\n", remove_line(&doc, -6, -3)); /* FAILURE */
    printf("%d\n", add_paragraph_after(&doc, -10)); /* FAILURE */

   return 0;
}