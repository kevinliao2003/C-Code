#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct point {
   int x, y;
};

/* Prototype of function executed by thread */
void *print_point(void *pointp);

int main(void) {
   pthread_t tid; /* Thread id */
   struct point pt = { 3, 5 };

   if (pthread_create(&tid, NULL, print_point, &pt) != 0) {
      fprintf(stderr, "pthread_create failed\n");
      exit(1);
   }

   /* Reaps thread, blocking until thread terminates */
   printf("Waiting for child to finish\n");
   if (pthread_join(tid, NULL) != 0) {
      fprintf(stderr, "pthread_join failed\n");
   }

   printf("In main after thread finished\n");

   return 0;
}

/* Code executed by the thread */
void *print_point(void *pointp) {
   struct point arg = *(struct point *) pointp;

   sleep(2); /* Simulating some work */
   printf("Point: (%d, %d)\n", arg.x, arg.y);

   return NULL;
}
