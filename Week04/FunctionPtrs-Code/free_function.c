#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* By using function pointers we can */
/* functions as part of a structure. */
typedef struct {
   char *container_name;
   void *item;
   void (*free_func)(void *); /* Matches void free(void *ptr); */ 
} Container; 

typedef struct {
   char *description;
   int weight;
} Computer;


void add_item_to_container(Container *container,
                           const char *container_name,
                           void *item, void (*free_func)(void *));
void destroy_container_contents(Container *container);
char *get_container_name(Container *container);
void *get_item(Container *container);
Computer *create_computer(const char *description, int weight);
void destroy_computer(void *computer);


void add_item_to_container(Container *container,
                           const char *container_name,
                           void *item, void (*free_func)(void *)) {
   /* Allocates memory for the new container's name */
   container->container_name = malloc(strlen(container_name) + 1);
   /* Copies the container's name */
   strcpy(container->container_name, container_name);
   container->item = item;
   container->free_func = free_func; /* FUNCTION POINTER */
}

void destroy_container_contents(Container *container) {
   printf("Destroying contents of container \"%s\"\n",
          container->container_name);
   /* Frees the container's memory */
   free(container->container_name);
  
   /* Frees the function's memory, if it is NOT NULL */                
   if (container->free_func != NULL) {
       container->free_func(container->item);
   }
}

char *get_container_name(Container *container) {
   return container->container_name;
}

void *get_item(Container *container) {
   return container->item;
}

/* Example of item we can store in container */
Computer *create_computer(const char *description, int weight) {
   /* Allocates memory for the new computer */
   Computer *computer = malloc(sizeof(Computer));
   /* Checks if the memory allocation was successful */
   if (computer == NULL) {
      exit(EXIT_FAILURE);
   }

   /* Allocates memory for the computer description */
   computer->description = malloc(strlen(description) + 1);
   /* Copies the description to the structure */
   strcpy(computer->description, description);
   computer->weight = weight;

   return computer;
}

void destroy_computer(void *computer) {
   /* Frees the description, 
   and then the computer structure's memory */
   free (((Computer *)computer)->description);
   free (computer);
}

int main(void) {
   Container computer_container, int_container, message_container;
   Computer *computer = create_computer("Nice laptop", 8);
   char *description, *str;
   int value = 100, retrieved;
   const char *message = "Terps";

   add_item_to_container(&computer_container, "computer container #1",
                         computer, destroy_computer); /* Function as parameter */
   
   description = ((Computer *)get_item(&computer_container))->description;
   printf("Description: %s\n", description);
   destroy_container_contents(&computer_container);

   /* Using NULL as free function */
   add_item_to_container(&int_container, "container with an integer",
                         &value, NULL);
   retrieved  = *(int *)get_item(&int_container);
   printf("Integer retrieved %d\n", retrieved);
   destroy_container_contents(&int_container);

   /* In this case the container will not destroy the item */
   str = malloc(strlen(message) + 1);
   strcpy(str, message);
   add_item_to_container(&message_container, "container with message",    
                         str, NULL);
   printf("Message is \"%s\"\n", (char *)get_item(&message_container));
   destroy_container_contents(&message_container);
   /* Freeing the string */
   free(str);

   return 0;    
}
