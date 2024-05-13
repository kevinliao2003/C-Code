#include <stdio.h>

#define MAX_COURSES 4

typedef struct {
   int section_number;
   int num_students;
} Section;

typedef struct {
   int course_number;
   Section section1, section2; /* A struct within a struct */
} Course;

int main(void) {
   Section honors_section = {1, 50};
   Course cs131 = {131, {0}, {2, 100}}; /* Only 1 value provided for section1 */
   Section *ptr;

   Course all_courses[MAX_COURSES]; /* Array of structures */
   
   cs131.section1 = honors_section;  /* Referring to a whole Section */
   cs131.section2.num_students = 200; /* Referring to one field of a Section in the course */

   all_courses[1].course_number = 216;  
   all_courses[1].section1.section_number = 1;
   all_courses[1].section1.num_students = 150;

   /* Using a pointer to simplify handling structure fields */
   ptr = &all_courses[1].section1;
   printf("Section #1 number is %d\n", ptr->section_number); 
   printf("Section #1 number of students is %d\n", ptr->num_students); 

   return 0;
}
