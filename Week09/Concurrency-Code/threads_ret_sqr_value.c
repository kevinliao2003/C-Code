#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Prototype of function executed by thread */
void *get_square(void *args);

int main(void) {
   pthread_t tid;
   void *result_ptr = NULL;
   int argument;

   printf("Input value to compute square: ");
   scanf("%d", &argument);

   pthread_create(&tid, NULL, get_square, &argument);
   pthread_join(tid, &result_ptr);      /* Notice use of & */
   printf("Square of %d is %d \n", argument, *(int *) result_ptr);

   free(result_ptr); /* Freeing memory allocated by thread */

   return 0;
}

/* Function executed by thread */
void *get_square(void *args) {
   int argument = *(int *) args;
   int *answer_ptr = malloc(sizeof(int));

   *answer_ptr = argument * argument;

   return answer_ptr;
}
