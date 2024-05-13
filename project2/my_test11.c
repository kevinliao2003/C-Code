#include <stdio.h>
#include <string.h>
#include "document.h"

int main() {
   Document doc;
   const char *doc_name = "Quiz Description";
   int paragraph_number, line_number;

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

   /* Resets document */
   reset_document(&doc);

   print_document(&doc);

   return 0;
}