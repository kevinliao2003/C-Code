/*
Kevin Liao
UID: 117815542
Directory ID: kliao
*/

#include <stdio.h>
#include <math.h>

void sort_by_values(int num_assignments, int nums_arr[], int scores_arr[],
                    int weights_arr[], int days_arr[]);
void remove_lowest(int num_assignments, int num_drop, int nums_arr[],
                   int scores_arr[], int weights_arr[], char removed[]);
double get_numeric_score(int num_assignments, int points_penalty,
                         int nums_arr[], int scores_arr[], int weights_arr[],
                         int days_arr[], char removed[]);
double get_mean(int num_assignments, int points_penalty, int scores_arr[],
                int days_arr[]);
double get_standard_deviation(int num_assignments, int points_penalty,
                              double mean, int scores_arr[], int days_arr[]);
int valid_assignment(int num_assignments, int assignment_num, int score,
                     int weight);
void swap(int *num1, int *num2);
void print_all(int num_assignments, int nums_arr[], int scores_arr[],
               int weights_arr[], int days_arr[]);

#define SIZE 50

int main() {
   int num_assignments = 0, points_penalty = 0, num_drop = 0;
   char generate = ' ';
   int assignment_num = 0, score = 0, weight = 0, days_late = 0;
   /* array of assignment numbers, scores, weights, and days */
   int nums_arr[SIZE], scores_arr[SIZE], weights_arr[SIZE], days_arr[SIZE];
   int index, weight_total = 0;
   /* dropped assignments, 'r' to denote a dropped assignment */
   char removed[SIZE + 1];
   double mean, standard_deviation, numeric_value;

   scanf("%d %d %c", &points_penalty, &num_drop, &generate);
   scanf("%d", &num_assignments);

   /* user inputs data for assignments */
   for (index = 0; index < num_assignments; index++) {
      scanf("%d, %d, %d, %d", &assignment_num, &score, &weight, &days_late);
      nums_arr[index] = assignment_num;
      scores_arr[index] = score;
      weights_arr[index] = weight;
      days_arr[index] = days_late;
      weight_total = weight_total + weight;
   }

   /* if weights don't add up to 100 */
   if (weight_total != 100) {
      printf("Weight total: %d\n", weight_total);
      printf("ERROR: Invalid values provided\n");
   } else {
      /* assignments are sorted by value */
      sort_by_values(num_assignments, nums_arr, scores_arr, weights_arr,
                     days_arr);

      /* the lowest n # of assignments are dropped */
      remove_lowest(num_assignments, num_drop, nums_arr, scores_arr,
                    weights_arr, removed);

      numeric_value = get_numeric_score(num_assignments, points_penalty,
                                        nums_arr, scores_arr, weights_arr,
                                        days_arr, removed);
      printf("Numeric Score: %5.4f\n", numeric_value);
      printf("Points Penalty Per Day Late: %d\n", points_penalty);
      printf("Number of Assignments Dropped: %d\n", num_drop);
      printf("Values Provided:\n");
      printf("Assignment, Score, Weight, Days Late\n");

      /* prints out all assignments */
      print_all(num_assignments, nums_arr, scores_arr, weights_arr, days_arr);

      /* if the user wants statistical information */
      if (generate == 'Y' || generate == 'y') {
         mean =
            get_mean(num_assignments, points_penalty, scores_arr, days_arr);
         standard_deviation =
            get_standard_deviation(num_assignments, points_penalty, mean,
                                   scores_arr, days_arr);
         printf("Mean: %5.4f, Standard Deviation: %5.4f\n", mean,
                standard_deviation);
      }
   }

   return 0;
}

/* sorts the values (score x weight) from least to greatest */
void sort_by_values(int num_assignments, int nums_arr[], int scores_arr[],
                    int weights_arr[], int days_arr[]) {
   int index1, index2;

   /* sorts using a bubble sort */
   for (index1 = 0; index1 < num_assignments; index1++) {
      for (index2 = index1 + 1; index2 < num_assignments; index2++) {
         /* if 2 values are out of order */
         if (scores_arr[index1] * weights_arr[index1] >
             scores_arr[index2] * weights_arr[index2]) {
            /* rearranges the scores */
            swap(&scores_arr[index1], &scores_arr[index2]);

            /* rearranges the assignment numbers */
            swap(&nums_arr[index1], &nums_arr[index2]);

            /* rearranges the weights */
            swap(&weights_arr[index1], &weights_arr[index2]);

            /* rearranges the days left */
            swap(&days_arr[index1], &days_arr[index2]);
         }
      }
   }
}

/* removes n number of lowest scores */
void remove_lowest(int num_assignments, int num_drop, int nums_arr[],
                   int scores_arr[], int weights_arr[], char removed[]) {
   /* boundaries - marks the indexes of where values change 
      boundaries_index - index of boundaries[] 
      nums_index - index of nums_arr[] 
      index - traces through boundaries[] 
      start - start pos to search for smallest assignment # 
      num_dropped - # of dropped assignments */
   int boundaries[SIZE], boundaries_index = 0, nums_index = 1, index = 0,
      start = 0, num_dropped = 0;

   /* builds boundaries[] */
   while (nums_index < num_assignments) {
      int curr_val = scores_arr[nums_index] * weights_arr[nums_index];
      int prev_val = scores_arr[nums_index - 1] * weights_arr[nums_index - 1];

      if (curr_val != prev_val) {
         boundaries[boundaries_index] = nums_index;
         boundaries_index++;
      }
      nums_index++;
   }
   boundaries[boundaries_index] = nums_index;

   /* removes n # of assignments */
   while (num_dropped != num_drop) {
      if (index <= boundaries_index) {
         /* smallest - smallest assignment # */
         int curr = boundaries[index], smallest = SIZE + 1;

         while (start < curr) {
            int curr_num = nums_arr[start];     /* assignment # */
            if (removed[curr_num - 1] != 'r' && curr_num < smallest) {
               smallest = curr_num;
            }
            start++;
         }

         /* if all assignments of a value HAVEN'T been removed */
         if (smallest != SIZE + 1) {
            removed[smallest - 1] = 'r';
            num_dropped++;
         }

         index++;
         start = curr;
      } else {
         index = 0;
         start = 0;
      }
   }
}

/* computes the numeric score */
double get_numeric_score(int num_assignments, int points_penalty,
                         int nums_arr[], int scores_arr[], int weights_arr[],
                         int days_arr[], char removed[]) {
   double numeric_score = 0;
   int index, weight_total = 0;

   for (index = 0; index < num_assignments; index++) {
      int num = nums_arr[index]; /* assignment # at given index */
      int score = scores_arr[index]; /* score at given index */
      int weight = weights_arr[index]; /* weight at given index */
      int days = days_arr[index]; /* days late at given index */

      if (removed[num - 1] != 'r') {
         int val = score - points_penalty * days; /* value at given index */

         /* if score < 0 after the late penalty */
         if (val < 0) {
            val = 0;
         }

         val *= weight;
         numeric_score += val;
         weight_total += weight;
      }
   }

   /* if no scores have been added to the numeric score */
   if (weight_total == 0) {
      return 0;
   } else {
      return numeric_score / weight_total;
   }
}

/* computes the mean */
double get_mean(int num_assignments, int points_penalty, int scores_arr[],
                int days_arr[]) {
   int index;
   double mean = 0;

   for (index = 0; index < num_assignments; index++) {
      int score = scores_arr[index];    /* score at given index */
      int days = days_arr[index];       /* days late at given index */
      mean += score - points_penalty * days;
   }

   return mean / num_assignments;
}

/* computes the standard deviation */
double get_standard_deviation(int num_assignments, int points_penalty,
                              double mean, int scores_arr[], int days_arr[]) {
   int index;
   double standard_deviation = 0;

   for (index = 0; index < num_assignments; index++) {
      /* value at given index */
      int value = scores_arr[index] - points_penalty * days_arr[index];
      standard_deviation += pow(value - mean, 2);
   }

   return sqrt(standard_deviation / num_assignments);
}

/* swaps two values */
void swap(int *num1, int *num2) {
   int temp = *num1;
   *num1 = *num2;
   *num2 = temp;
}

/* prints out all scores */
void print_all(int num_assignments, int nums_arr[], int scores_arr[],
               int weights_arr[], int days_arr[]) {
   int index1, index2;

   /* uses a bubble sort to sort assignments by assignment # */
   for (index1 = 0; index1 < num_assignments; index1++) {
      for (index2 = index1 + 1; index2 < num_assignments; index2++) {
         /* if 2 assignments are out of order */
         if (nums_arr[index1] > nums_arr[index2]) {
            /* rearranges the scores */
            swap(&scores_arr[index1], &scores_arr[index2]);

            /* rearranges the assignment numbers */
            swap(&nums_arr[index1], &nums_arr[index2]);

            /* rearranges the weights */
            swap(&weights_arr[index1], &weights_arr[index2]);

            /* rearranges the days left */
            swap(&days_arr[index1], &days_arr[index2]);
         }
      }
   }

   /* prints out all assignments */
   for (index1 = 0; index1 < num_assignments; index1++) {
      printf("%d, %d, %d, %d\n", nums_arr[index1], scores_arr[index1],
             weights_arr[index1], days_arr[index1]);
   }
}
