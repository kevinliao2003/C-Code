#include <stdio.h>

int is_valid(int value) {
   return (value > 0) && (value % 2 == 0);
}

int compute_sum(int start, int end) {
   int i, sum = 0;

   for (i = start; i <= end; i++) {
      sum += i;
   }

   return sum;
}

int process() {
   int lower_limit, upper_limit, answer = -1;

   printf("Enter lower limit: ");
   scanf("%d", &lower_limit);
   printf("Enter upper limit: ");
   scanf("%d", &upper_limit);

   if (is_valid(lower_limit) && is_valid(upper_limit)) {
      answer = compute_sum(lower_limit, upper_limit);
   } 

   return answer;
}

int main() {
   printf("Sum is %d\n", process());
   printf("Bye bye\n");

   return 0;
}
