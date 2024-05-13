#include <stdio.h>

int main() {
   int age, values_read;
   int* age_ptr = &age;
   float salary;
    
   printf("Enter your age and salary (using <age>-<salary> format): "); 

   /* This example shows we don't always use & in variables of a scanf */
   values_read = scanf("%d-%f", age_ptr, &salary);
   if (values_read != 2) {
      printf("Invalid data provided\n");
   } else {
      printf("Provided values Age: %d, Salary: $%.2f\n", age, salary);
   }

   return 0;
}
