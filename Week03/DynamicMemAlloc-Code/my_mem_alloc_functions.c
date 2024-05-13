#include <stdio.h>
#include <stdlib.h>    /* For malloc  */
#include <err.h>       /* For function err */
#include <sysexits.h>  /* For EX_OSERR (/usr/include/sysexits.h) */

#define BLOCK_SIZE 1024

void *my_malloc(size_t num_of_bytes) {
   void *ptr = malloc(num_of_bytes);
   
   if (ptr == NULL) { /* Notice err */
      err(EX_OSERR, "malloc failure in function my_malloc");
   }

   return ptr;
}

void my_free(void **ptr) {
   free(*ptr);
   *ptr = NULL;
}

int main(void) {
   void *data;

   /* Checking my_free */
   data = my_malloc(BLOCK_SIZE);
   my_free(&data);
   if (data == NULL) {
      printf("data pointer set to null\n");
   }

   return 0;
}
