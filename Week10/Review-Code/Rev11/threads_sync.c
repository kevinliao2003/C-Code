#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define LOOPS 10000000

static int count = 0;
static pthread_mutex_t mutex;

void *counter(void *args) {
   int i;

   for (i = 0; i < LOOPS; i++) {
      pthread_mutex_lock(&mutex);
      count++;
      pthread_mutex_unlock(&mutex);
   }
   printf("Executed %d times\n", i);

   return NULL;
}

int main() {
   pthread_t tids[2];

   pthread_mutex_init(&mutex, NULL);

   pthread_create(&tids[0], NULL, counter, NULL);
   pthread_create(&tids[1], NULL, counter, NULL);
   pthread_join(tids[0], NULL);
   pthread_join(tids[1], NULL);
   printf("Count: %d\n", count);

   pthread_mutex_destroy(&mutex);

   return 0;
}
