#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "calendar.h"
#include "my_memory_checker_216.h"

static int comp_minutes(const void *ptr1, const void *ptr2) {
   return ((Event *)ptr1)->duration_minutes - ((Event *)ptr2)->duration_minutes;
}

/* Description here: This test checks ...  */
static int test1() {
   int days = 7;
   Calendar *calendar;

   if (init_calendar("Spr", days, comp_minutes, NULL, &calendar) == SUCCESS) {
      if (print_calendar(calendar, stdout, 1) == SUCCESS) {
         return destroy_calendar(calendar);
      }
   }
    
   return FAILURE;
}

/* This test checks for all functionalities of calendar */
static int test2() {
   int days = 3, start_time_mil = 900, duration_minutes = 50;
   int activity_day = 1, num = 10;
   Calendar *calendar;
   void *info;
   Event *events;
   info = &num;

   start_memory_check();

   /* A calendar is instantiated */
   init_calendar("Summer Calendar", days, comp_minutes, NULL, &calendar);

   /* An event is added and added again. 
   FAILURE is returned after the second attempt. 
   Information about the event is printed out. */
   add_event(calendar, "zoo visit", start_time_mil, duration_minutes, 
             NULL, activity_day);
   printf("Info: %d\n", (int*)(get_event_info(calendar, "zoo visit")));
   printf("Add zoo visit again: %d\n", add_event(calendar, "zoo visit", 
   start_time_mil, duration_minutes, NULL, activity_day)); /* FAILURE */

   /* Another event is added, and information about it is prined out */
   num = 20;
   info = &num;
   add_event(calendar, "review meeting", 800, 80, NULL, 1);
   printf("Info: %d\n", (int*)(get_event_info(calendar, "review meeting")));

   /* More events are added, and some are removed. */
   add_event(calendar, "group meeting", 500, 60, NULL, 1);
   add_event(calendar, "celebration", 350, 45, NULL, 1);
   add_event(calendar, "party", 550, 75, NULL, 1); 
   add_event(calendar, "dinner", 330, 10, NULL, 1);
   remove_event(calendar, "group meeting");
   remove_event(calendar, "dinner");
   remove_event(calendar, "review meeting");

   /* More events are added.
   FAILURE is returned, since a nonexistent event is trying to be removed. */
   add_event(calendar, "computer science", 200, 5, NULL, 2);
   add_event(calendar, "russian", 220, 50, NULL, 2);
   add_event(calendar, "leisure", 180, 45, NULL, 2);
   remove_event(calendar, "computer science");
   remove_event(calendar, "russian");
   printf("Remove russian again: %d\n", remove_event(calendar, "russian")); /* FAILURE */

   /* The find_event and find_event_in_day methods are tested. */
   add_event(calendar, "lunch", 1200, 45, NULL, 3);
   printf("lunch found: %d\n", find_event(calendar, "lunch", &events));
   printf("russian found: %d\n", find_event(calendar, "russian", &events));
   printf("leisure found in day 2: %d\n", find_event_in_day(calendar, "leisure", 2,
                      &events));
   printf("Lunch found: %d\n", find_event(calendar, "Lunch", &events));
   printf("leisure found in day 1: %d\n", find_event_in_day(calendar, "leisure", 1,
                      &events));

   /* The clear_day and clear_calendar methods are tested. */
   clear_day(calendar, 1);
   clear_calendar(calendar);

   /* The contents of the calendar are printed and destroyed. */
   print_calendar(calendar, stdout, 1);
   destroy_calendar(calendar);

   stop_memory_check(); /* NO MEMORY LEAKS */

   exit(EXIT_SUCCESS);

   return SUCCESS;
}

int main() {
   int result = SUCCESS;

   start_memory_check();

   printf("Test 1\n");
   if (test1() == FAILURE) result = FAILURE;
   printf("\n");
   
   printf("Test 2\n");
   if (test2() == FAILURE) result = FAILURE;

   stop_memory_check();
   
   if (result == FAILURE) {
      exit(EXIT_FAILURE);
   }

   return EXIT_SUCCESS;
}
