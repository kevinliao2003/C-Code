#include <stdio.h>
#include <string.h>

#define MAX_LEN 80

typedef struct person {
   char *name;
   int age;
} Person;

typedef struct student {
   char name[MAX_LEN + 1];
   float gpa;
} Student;

int main() {
   char persons_name[MAX_LEN + 1] = "Mike";
   char students_name[MAX_LEN + 1] = "Rachel";
   Person p1, p2;
   Student s1, s2;

   printf("\n*** Person ***\n");
   p1.name = persons_name;
   p1.age = 30;
   p2 = p1;
   printf("%s %d\n", p2.name, p2.age);

   printf("After Updating p2's name\n");
   p2.age = 40;
   strcpy(p2.name, "Laura");
   printf("p1: %s %d\n", p1.name, p1.age);
   printf("p2: %s %d\n", p2.name, p2.age);
  
   printf("\n*** Student ***\n");
   strcpy(s1.name, students_name);
   s1.gpa = 4.0;
   s2 = s1;
   printf("%s %.2f\n", s2.name, s2.gpa);
   printf("After Updating s2's name\n");
   strcpy(s2.name, "Monica");
   printf("s1: %s %.2f\n", s1.name, s1.gpa);
   printf("s2: %s %.2f\n", s2.name, s2.gpa);

   return 0;
}
