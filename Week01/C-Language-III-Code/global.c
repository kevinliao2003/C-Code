#include <stdio.h>

/* Notice the global variables convention (g_) */
int g_years = 10;  /* What if we don't initialize it? */

void process() {
   /* Following printf will not compile */
   /* printf("g_salary in process() %f\n", g_salary); */
   g_years++;
}

double g_salary = 3000.00; /* Visible from this point on */

int main() {
   printf("g_years before process() call: %d\n", g_years);
   process();
   printf("g_years after process() call: %d\n", g_years);
   printf("g_salary in main() %f\n", g_salary);

   return 0;
}
