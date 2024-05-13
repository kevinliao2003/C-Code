#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
   time_t now, start, end;
   struct tm *tm_ptr;
   int i, sleep_time_in_secs = 3;

   now = time(NULL);            /* Get the current time */
   tm_ptr = localtime(&now);    /* Cover to struct tm */
   printf("\nCurrent Time (using tm structure) = %d:%02d:%02d\n",
          tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);
   printf("Current Time (using ctime) = %s", ctime(&now));

   /* Computing time difference */
   printf("\nAbout to sleep for %d seconds...", sleep_time_in_secs);
   fflush(stdout);
   start = time(NULL);          /* Get the currrent time */
   sleep(sleep_time_in_secs);
   end = time(NULL);            /* Get the end time */
   printf("\nTime difference (seconds, using difftime): %f\n",
          difftime(end, start));

   /* Using time for random number generation */
   printf("\nRandom numbers using time as seed\n");
   srand(time(NULL));
   for (i = 1; i <= 10; i++) {
      printf("%d ", rand() % 100);
   }
   printf("\n\n");

   return 0;
}
