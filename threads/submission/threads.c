/* Kevin Liao (kliao), Ana Clemmer (aclemmer), Alexander Hearn (xhearn) */
 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
 
/* needed for time functions */
#include <sys/time.h>
#include <sys/resource.h>
 
static pthread_mutex_t mutex;
 
/* function executed by thread */
void *get_num(void *args) {
    int num = *(int *)args;
    int *num_ptr = malloc(sizeof(int));
 
    *num_ptr = num;
    printf("Number: %d\n", *num_ptr);
    return num_ptr;
}
 
/* computes time difference */
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
 
int main(int argc, char *argv[]) {
    /* argv[0] is a.out */
    int num_elements = atoi(argv[1]);
    int num_threads = atoi(argv[2]);
    int seed = atoi(argv[3]);
    int task = atoi(argv[4]);
    int print_yn = atoi(argv[5]);
    pthread_t tids[80]; /* Thread ids */
    int index, ids[80], sum = 0, max = 0;
    struct rusage start_ru, end_ru; /* user time */
    struct timeval start_wall, end_wall; /* wall clock time */
    /* diff_ru_utime - user time difference
       diff_wall - wall clock time difference
       diff_ru_stime - system time difference */
    struct timeval diff_ru_utime, diff_wall, diff_ru_stime;
    void *result_ptr = NULL;
 
    /* get start time */
    getrusage(RUSAGE_SELF, &start_ru);
    gettimeofday(&start_wall, NULL);
 
    /* creates an array of integers */
    srand((unsigned)seed);
    for (index = 0; index < num_elements; index++) {
        ids[index] = rand();
    }

    pthread_mutex_init(&mutex, NULL); /* prevents data race */
 
    /* creates an array of threads */
    for (index = 0; index < num_threads; index++) {
        pthread_create(&tids[index], NULL, get_num, &ids[index]);  
 
    }
    for (index = 0; index < num_threads; index++) {
        if (task == 2) {
            pthread_join(tids[index], &result_ptr);
            sum += *(int *)result_ptr;
            free(result_ptr);
        } else if (task == 1) {
            pthread_join(tids[index], &result_ptr);
            if (*(int *)result_ptr > max) {
                max = *(int *)result_ptr;
            }
            free(result_ptr);
        }
    }
 
    /* prints sum or max */
    if (print_yn) {
        if (task == 1) { /* prints max */
            printf("Max: %d\n", max);
        } else if (task == 2) { /* prints sum */
            printf("Sum: %d\n", sum);
        }
    }
 
    /* get end time */
    getrusage(RUSAGE_SELF, &end_ru);
    gettimeofday(&end_wall, NULL);
 
    /* computes time difference */
    diff_ru_utime = tv_delta(start_ru.ru_utime, end_ru.ru_utime);
    diff_ru_stime = tv_delta(start_ru.ru_stime, end_ru.ru_stime);
    diff_wall = tv_delta(start_wall, end_wall);
 
    /* displays the time differences */
    printf("User time: %ld.%06ld\n", diff_ru_utime.tv_sec,
          diff_ru_utime.tv_usec);
    printf("System time: %ld.%06ld\n", diff_ru_stime.tv_sec,
          diff_ru_stime.tv_usec);
    printf("Wall time: %ld.%06ld\n", diff_wall.tv_sec, diff_wall.tv_usec);
 
    pthread_mutex_destroy(&mutex);
 
    return 0;
}