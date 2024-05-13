#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <malloc.h>
#include <fcntl.h>
#include <sys/resource.h>

/* same as 0666, but a bit more symbolic (we could use #define DEF_MODE 0666 )*/
#define DEF_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

struct timeval tv_delta(struct timeval start, struct timeval end) {
   struct timeval delta = end;

   delta.tv_sec -= start.tv_sec;
   delta.tv_usec -= start.tv_usec;
   if (delta.tv_usec < 0) {
      delta.tv_usec += 1000000;
      delta.tv_sec--;
   }

   return delta;
}

int main() {
   struct rusage start_ru, end_ru;
   struct timeval start_wall, end_wall;
   struct timeval diff_ru_utime, diff_wall, diff_ru_stime;
   int n = 50000, i, j, *p;

   /* Collecting information */
   getrusage(RUSAGE_SELF, &start_ru);
   gettimeofday(&start_wall, NULL);



   /***** START of task we want to time *****/
   printf("Allocating and deallocating memory\n");
   for (i = 0; i < n; i++){
      p = calloc(n, sizeof(int));
      for (j = 0; j < n; j++){
         p[j] = j * i;
      }
      free(p);
   }

   printf("Writing to file\n");
   for (i = 0; i <= 100; i++) {
      int fd = open("temp_file_remove_it.txt",  O_WRONLY|O_TRUNC|O_CREAT, DEF_MODE);
      write(fd, &n, sizeof(int));
      close(fd);
   }
   /***** END of task we want to time *****/



   /* Collecting information */
   gettimeofday(&end_wall, NULL);
   getrusage(RUSAGE_SELF, &end_ru);


  
   /* Computing difference */
   diff_ru_utime = tv_delta(start_ru.ru_utime, end_ru.ru_utime);
   diff_ru_stime = tv_delta(start_ru.ru_stime, end_ru.ru_stime);
   diff_wall = tv_delta(start_wall, end_wall);

   printf("User time: %ld.%06ld\n", diff_ru_utime.tv_sec, diff_ru_utime.tv_usec);
   printf("System time: %ld.%06ld\n", diff_ru_stime.tv_sec, diff_ru_stime.tv_usec);
   printf("Wall time: %ld.%06ld\n", diff_wall.tv_sec, diff_wall.tv_usec);

   return 0;
}
