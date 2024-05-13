#include <stdio.h>
#include <unistd.h>

/*
 * Execute "time sleeper"
 */
int main(void) {
   long x = 999999999;

   printf("Performing some CPU work, please wait\n");
   while (x-- > 0);          

   printf("About to sleep for 5 seconds\n");
   fflush(stdout);
   sleep(5);

   printf("Done\n");

   return 0;
}
