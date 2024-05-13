#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "event.h"
#include "calendar.h"
#include "my_memory_checker_216.h"

static int comp_duration_minutes(const void *ptr1, const void *ptr2) {
   return ((Event *)ptr1)->duration_minutes - ((Event *)ptr2)->duration_minutes;
}

int main(void) {
   int days = 3, start_time_mil = 900, duration_minutes = 50;
   int activity_day = 1, num = 10;
   Calendar *calendar;
   void *info;
   Event *events;
   info = &num;

   start_memory_check();

   init_calendar("Summer Calendar", days, comp_duration_minutes, NULL, 
   &calendar);

   add_event(calendar, "zoo visit", start_time_mil, duration_minutes, 
             NULL, activity_day);
   printf("Info: %d\n", (int*)(get_event_info(calendar, "zoo visit")));
   printf("Add zoo visit again: %d\n", add_event(calendar, "zoo visit", 
   start_time_mil, duration_minutes, NULL, activity_day)); /* FAILURE */

   num = 20;
   info = &num;
   add_event(calendar, "review meeting", 800, 80, NULL, 1);
   printf("Info: %d\n", (int*)(get_event_info(calendar, "review meeting")));
   print_calendar(calendar, stdout, 1);

   add_event(calendar, "group meeting", 500, 60, NULL, 1);
   add_event(calendar, "celebration", 350, 45, NULL, 1);
   add_event(calendar, "party", 550, 75, NULL, 1); 
   add_event(calendar, "dinner", 330, 10, NULL, 1);
   add_event(calendar, "exam", 320, 90, NULL, 1); /* Insert at end */
   remove_event(calendar, "group meeting");
   remove_event(calendar, "dinner");
   remove_event(calendar, "review meeting");
   print_calendar(calendar, stdout, 1);

   /* Remove at beginning */
   add_event(calendar, "computer science", 200, 5, NULL, 2);
   add_event(calendar, "russian", 220, 50, NULL, 2);
   /* Remove at end */
   add_event(calendar, "leisure", 180, 45, NULL, 2);
   remove_event(calendar, "computer science");
   remove_event(calendar, "russian");
   /* FAILURE */
   printf("Remove russian again: %d\n", remove_event(calendar, "russian"));

   add_event(calendar, "lunch", 1200, 45, NULL, 3);

   printf("lunch found: %d\n", find_event(calendar, "lunch", &events));
   printf("russian found: %d\n", find_event(calendar, "russian", &events));
   printf("leisure found in day 2: %d\n", find_event_in_day(calendar, 
   "leisure", 2, &events));
   printf("Lunch found: %d\n", find_event(calendar, "Lunch", &events));
   printf("leisure found in day 1: %d\n", find_event_in_day(calendar, 
   "leisure", 1, &events));

   clear_day(calendar, 1);
   clear_calendar(calendar);

   print_calendar(calendar, stdout, 1);
   destroy_calendar(calendar);

   stop_memory_check();

   exit(EXIT_SUCCESS);
}