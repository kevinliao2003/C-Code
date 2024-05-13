#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define LOOPS 10000000

static int count = 0;

void *counter(void *args) {
   int i;

   for (i = 1; i <= LOOPS; i++) {
      count++;
   }
   printf("Executed %d times\n", i - 1);

   return NULL;
}

int main(void) {
   pthread_t tids[2]; /* Thread ids */

   /* Creating threads */
   pthread_create(&tids[0], NULL, counter, NULL);
   pthread_create(&tids[1], NULL, counter, NULL);

   /* Wating for them to finish */
   pthread_join(tids[0], NULL);
   pthread_join(tids[1], NULL);

   printf("Count: %d\n", count);

   return 0;
}
