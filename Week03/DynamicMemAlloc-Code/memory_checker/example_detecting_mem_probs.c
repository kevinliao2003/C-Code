#include <stdio.h>
#include <stdlib.h>
#include <mcheck.h>
#include <malloc.h>

#if defined(MY_DEBUG)
#include "my_memory_checker_216.h"
#endif

static int get_choice();
static void memory_leak_example();
static void double_free_example();
static void out_of_bounds_write_example();

static int get_choice() {
   int choice;

   printf("1. Memory leak\n");
   printf("2. Double free\n");
   printf("3. Writing out of area\n");
   printf("4. Dangling pointer\n");
   printf("Enter number of problem you want to see: ");
   scanf("%d", &choice);

   return choice;
}

static void memory_leak_example() {
   int *p = malloc(sizeof(int));

   *p = 20;
   printf("Value is %d\n", *p);
}

static void double_free_example() {
   int *p = malloc(sizeof(int));

   *p = 20;
   printf("Value is %d\n", *p);
   free(p);
   free(p);
}

static void out_of_bounds_write_example() {
   int *p = malloc(sizeof(int));

   *(p + 1) = 20;
   printf("Value is %d\n", *p);
   free(p);
}

/* We don't get error message */
static void dangling_pointer_example() {
   int *p = malloc(sizeof(int));

   *p = 777;
   printf("Value is %d\n", *p);

   /* deallocating */
   free(p); 

   /* p is a dangling pointer */
   *p = 888;
   printf("Value is %d\n", *p);

}

int main(void) {

   #if defined(MY_DEBUG)
   /***** Starting memory checking *****/
   start_memory_check(); 
   /***** Starting memory checking *****/
   #endif

   switch(get_choice()) {
      case 1:
         memory_leak_example();
         break;
      case 2:
         double_free_example();
         break;
      case 3:
         out_of_bounds_write_example();
         break; 
      case 4:
         dangling_pointer_example();
         break; 
      default:
         fprintf(stderr, "Invalid choice\n");
	 break;
   }

   #if defined(MY_DEBUG)
   /****** Gathering memory checking info *****/
   stop_memory_check(); 
   /****** Gathering memory checking info *****/
   #endif

   return 0;
}
