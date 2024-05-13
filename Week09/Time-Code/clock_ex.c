#include <stdio.h>
#include <malloc.h>
#include <time.h>

int main(void) {
   int n = 40000, i, j, *p;
   clock_t start, end, ticks_used;
   double cpu_time_used;

   printf("Performing some CPU work, please wait...");
   fflush(stdout);
   start = clock();
   for (i = 0; i < n; i++) {
      p = calloc(n, sizeof(int));
      for (j = 0; j < n; j++) {
         p[j] = j * i;
      }
      free(p);
   }
   end = clock();
   ticks_used = end - start;
   cpu_time_used = (double) ticks_used / CLOCKS_PER_SEC;

   printf("Initial number of clock ticks  = %ld\n", start);
   printf("Final number of clock ticks = %ld\n", end);
   printf("Ticks used = %ld\n", ticks_used);
   printf("CLOCKS_PER_SEC = %ld\n", CLOCKS_PER_SEC);
   printf("CPU time (secs) used = %f\n", cpu_time_used);

   return 0;
}
