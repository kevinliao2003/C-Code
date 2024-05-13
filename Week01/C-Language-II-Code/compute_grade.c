#include <stdio.h>

/* 
 * letter_grade prototype. Without it the function definition 
 * must appear appear before main.
 */
char letter_grade(float score);  /* prototype */

int main() {
   /* Providing values for score1 and score2 to */
   /* see what happens when not enough values   */
   /* are provided by user.                     */
   float score1 = 77, score2 = 88, avg;
   int values_read;

   printf("Enter two scores using <score1> and <score2> format: ");
   values_read = scanf("%f and %f", &score1, &score2);
   printf("The number of values read is %d\n", values_read);

   avg = (score1 + score2) / 2;
   printf("Average for %f and %f is %.2f\n", score1, score2, avg);

   printf("Your letter grade is %c\n", letter_grade(avg));

   return 0;
}

/* Function definition */
char letter_grade(float score) {
   char grade;

   if (score >= 90) {
      grade = 'A';
   } else if (score >= 80) {
      grade = 'B';
   } else {
      grade = 'F';
   }

   return grade; 
}
