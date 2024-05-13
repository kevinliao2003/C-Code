/*
Name: Kevin Liao
ID: 117815542
Directory ID: kliao
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calendar.h"
#include "my_memory_checker_216.h"

/* Initializes a Calendar structure based on the parameters provided */
int init_calendar(const char *name, int days,
                  int (*comp_func) (const void *ptr1, const void *ptr2),
                  void (*free_info_func) (void *ptr), Calendar ** calendar) {
    if (calendar == NULL || name == NULL || days < 1) {
        return FAILURE;
    } else {
        /* Allocates memory for the calendar structure */
        /* A temp struct is created for memory allocation */
        Calendar *temp = malloc(sizeof(Calendar));
        if (temp == NULL) {
            return FAILURE;
        }

        /* Allocates memory to the name field */
        temp->name = malloc(strlen(name) + 1);
        if (temp->name == NULL) {
            return FAILURE;
        } else {
            strcpy(temp->name, name);
        }

        /* Allocates memory to the events field */
        temp->events = calloc(days, sizeof(Event*));
        if (temp->events == NULL) {
            return FAILURE;
        }

        /* Initializes days, total_events, and the function parameters */
        temp->days = days;
        temp->total_events = 0;
        temp->comp_func = comp_func;
        temp->free_info_func = free_info_func;
        /* Dereferences the calendar double pointer and sets it to temp */
        *calendar = temp;
        return SUCCESS;
    }
}

/* Prints, to the designated output stream, the calendar’s name, days, 
and total number of events. 
If print all is true; otherwise this information will not be printed. */
int print_calendar(Calendar *calendar, FILE *output_stream, int print_all) {
    if (calendar == NULL || output_stream == NULL) {
        return FAILURE;
    } else {
        int index;

        /* If print_all is true, the calendar’s name, days, 
        and total number of events will be printed to the
        designated output stream */
        /* USES FPRINTF TO SEND THE INFORMATION TO STR */
        if (print_all == 1) {
            /* Adds calendar's name */
            fprintf(output_stream, "Calendar's Name: \"%s\"", calendar->name);
            fprintf(output_stream, "\n"); /* NEW LINE */
            /* Adds days */
            fprintf(output_stream, "Days: %d\n", calendar->days);;
            /* Adds total # of events */
            fprintf(output_stream, "Total Events: %d\n", 
            calendar->total_events);
            fprintf(output_stream, "\n"); /* EMPTY LINE */
        }

        /* Prints out information about each event */
        printf("**** Events ****\n");
        if (calendar->total_events > 0) {
            for (index = 0; index < calendar->days; index++) {
                Event *event = calendar->events[index];
                printf("Day %d\n", index + 1);
                while (event != NULL) {
                    printf("Event's Name: \"%s", event->name);
                    printf("\", Start_time: %d", event->start_time);
                    printf(", Duration: %d\n", event->duration_minutes);
                    event = event->next; /* Moves onto next event */
                }
            }
        }
    }

    return SUCCESS;
}

/* Adds the specified event to the list associated with the day parameter */
int add_event(Calendar *calendar, const char *name, int start_time,
              int duration_minutes, void *info, int day) {
    if (calendar == NULL || name == NULL || start_time < 0 || start_time > 2400
    || duration_minutes < 0 || day < 1 || day > calendar->days) {
        return FAILURE;
    } else {
        Event *event, *curr = calendar->events[day - 1],
        *prev = NULL, *insert;

        /* Checks if the event already exists */
        if (find_event(calendar, name, &event) == SUCCESS) {
            return FAILURE;
        }

        /* Allocates memory for the new event and the event's name */
        insert = malloc(sizeof(Event));
        if (insert == NULL) {
            return FAILURE;
        }
        insert->name = malloc(strlen(name) + 1);
        if (insert->name == NULL) {
            return FAILURE;
        } else {
            strcpy(insert->name, name);
        }
        /* Assigns the dimensions of the new event accordingly */
        insert->start_time = start_time;
        insert->duration_minutes = duration_minutes;
        insert->info = info; /* Might need to allocate dynamic */

        /* Updates the total # of events */
        calendar->total_events++;

        /* Finds where to insert the new event */
        /* comp_fun returns positive # */
        while (curr != NULL && calendar->comp_func(insert, curr) > 0) {
            prev = curr;
            curr = curr->next;
        }

        /* Inserts the new event */
        if (prev == NULL) { /* Insert at beginning */
            calendar->events[day - 1] = insert;
            insert->next = curr;
        } else {
            insert->next = curr;
            prev->next = insert;
        }

        return SUCCESS;
    }
}

/* Returns a pointer to the event with the specified name */
int find_event(Calendar *calendar, const char *name, Event **event) {
    if (calendar == NULL || name == NULL) {
        return FAILURE;
    } else {
        /* Loops through the days */
        int day;
        for (day = 1; day <= calendar->days; day++) {
            /* The event has been found in a specific day */
            if (find_event_in_day(calendar, name, day, event) == SUCCESS) {
                return SUCCESS;
            }
        }

        /* The event was NOT found in the calendar */
        return FAILURE;
    }
}

/* Returns a pointer to the event with the specified name 
in the specified day */
int find_event_in_day(Calendar *calendar, const char *name, int day,
                      Event **event) {
    if (calendar == NULL || name == NULL || day < 1 || day > calendar->days) {
        return FAILURE;
    } else {
        Event **events = calendar->events, *curr = events[day - 1];

        /* Checks if the event was found */
        while (curr != NULL) {
            /* The event has been found */
            if (!strcmp(curr->name, name)) {
                /* Assigns the event parameter to curr */
                *event = curr;
                return SUCCESS;
            }
            curr = curr->next;
        }

        /* The event has NOT been found */
        return FAILURE;
    }
}

/* Removes the specified event from the calendar 
and returns any memory allocated for the event */
int remove_event(Calendar *calendar, const char *name) {
    if (calendar == NULL || name == NULL) {
        return FAILURE;
    } else {
        int day = 1;
        Event **events = calendar->events;

        for (day = 1; day <= calendar->days; day++) {
            Event *prev = NULL; 
            Event *curr = events[day - 1];
            /* Looks for the event */
            while (curr != NULL && strcmp(curr->name, name) != 0) {
                prev = curr;
                curr = curr->next;
            }

            /* The event was found */
            if (curr != NULL && strcmp(curr->name, name) == 0) {
                /* Removes the event - BUG */
                if (prev == NULL) { /* Removes from the beginning */
                    calendar->events[day - 1] = curr->next;
                } else {
                    prev->next = curr->next;
                }

                /* Total # of events adjusted */
                calendar->total_events--;

                /* Deallocates memory for the event */
                if (curr->name != NULL) { 
                    free(curr->name);
                }
                if (curr->info != NULL && 
                calendar->free_info_func != NULL) {
                    calendar->free_info_func(curr->info);
                }
                free(curr);

                return SUCCESS;
            }
        }

        return FAILURE;
    }
}

/* Returns the info pointer associated with the specified event */
void *get_event_info(Calendar *calendar, const char *name) {
    /* Checks if the event was found */
    /* event has to be a single pointer, because if it were a double pointer,
    when event is dereferenced, it would be pointing to the first event in
    the linked list. However, we want it to point to the position where the
    specified event is located. */
    Event *event;
    if (find_event(calendar, name, &event) == SUCCESS) {
        return event->info;
    } else { /* If event was NOT found */
        return NULL;
    }
}

/* Removes all the event lists associated with the calendar and 
sets them to empty lists */
int clear_calendar(Calendar *calendar) {
    if (calendar == NULL) {
        return FAILURE;
    } else {
        /* Loops through all days */
        int day;
        for (day = 1; day <= calendar->days; day++) {
            /* Deallocates memory for all events in a specified day */
            clear_day(calendar, day);
        }

        /* Total # of events set to 0 */
        calendar->total_events = 0;

        return SUCCESS;
    }
}

/* Removes all the events for the specified day 
and sets the event list to empty */
int clear_day(Calendar *calendar, int day) {
    if (calendar == NULL || day < 1 || day > calendar->days) {
        return FAILURE;
    } else {
        Event *prev = NULL; /* Previous event */
        Event *curr = calendar->events[day - 1]; /* Current event */

        /* Clears all events in that specified day */
        while (curr != NULL) {
            /* Deallocates memory for the event name */
            if (curr->name != NULL) { 
                free(curr->name);
            }
            /* If event info is other than NULL
            and a free_info_function exists */
            if (curr->info != NULL && 
            calendar->free_info_func != NULL) {
                calendar->free_info_func(curr->info);
            }
            /* Deallocates memory for the event */
            prev = curr;
            curr = curr->next;
            free(prev);

            /* Total # of events adjusted accordingly */
            calendar->total_events--;
        }

        /* Sets the linked list to empty */
        calendar->events[day - 1] = NULL;

        return SUCCESS;
    }
}

/* Returns memory that was dynamically-allocated for the calendar */
int destroy_calendar(Calendar *calendar) {
    if (calendar == NULL) {
        return FAILURE;
    } else {
        clear_calendar(calendar);

        /* Deallocates memory for the calendar name, events, and calendar */
        free(calendar->name);
        free(calendar->events);
        free(calendar);

        return SUCCESS;
    }
}