#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int data;
   struct node *next;   
} Node;

/* In summary, if the head will change, ** must be used */

void create_list(Node **head); /* Notice ** */
void print_list(Node *head);
void print_list_recursive(Node *head);
static void print_list_recursive_aux(Node *head_aux);
int insert(Node **head, int new_value);
int find(Node *head, int target);
int delete(Node **head, int value);

void create_list(Node **head) { /* List head will change */
   *head = NULL;
}

/* The head node will not change, so ** is not used */
void print_list(Node *head) { /* Why no Node ** ? */
   if (!head) {
      printf("Empty list\n");
   } else {
      Node *current = head;

      while (current != NULL) {
         printf("%d ", current->data);

         current = current->next; 
      }
      printf("\n");
   }
}

void print_list_recursive(Node *head) {
   if (!head) {
      printf("Empty list\n");
   } else {
      print_list_recursive_aux(head);
   }
}

static void print_list_recursive_aux(Node *head_aux) {
   if (head_aux != NULL) {
      printf("%d ", head_aux->data);
      print_list_recursive_aux(head_aux->next);
   }
}

/* Insertin in increasing sorted order */
int insert(Node **head, int new_value) {  /* Why Node ** ? */
   Node *current = *head, *prev = NULL, *new_item;

   /* Finds where to insert the new node */
   while (current != NULL && new_value > current->data) {
      prev = current;
      current = current->next;
   }

   /* Allocates dynamic memory to the new node */
   new_item = malloc(sizeof(Node));
   /* Checks if the memory allocation was successful */
   if (new_item == NULL) {
      return 0;
   }
   /* Assigns the dimensions of the new node */
   new_item->data = new_value;
   new_item->next = current;
   if (prev == NULL) { /* Inserting at the beginning */ 
      *head = new_item;
   } else {
      prev->next = new_item;
   }

   return 1;
}

/* The head is not being changed, so ** is not needed */
int find(Node *head, int target) {  /* Why * ? */
   while (head != NULL && head->data != target) {
      head = head->next; /* Why we can change this "head" ? */
   }

   /* Returns whether or not the target was found */
   return head != NULL;
}

/* The head value could be changed, so ** is necessary */
int delete(Node **head, int value) { /* Why ** ? */
   Node *prev = NULL, *current = *head;

   /* Finds the node to delete */
   while (current != NULL && current->data != value) {
      prev = current;
      current = current->next;
   }
   if (current == NULL){
      return 0;  /* Not found */
   }
   if (prev == NULL) {
      *head = current->next;  /* Deleted first item, so head needs update */
   } else {
      prev->next = current->next;
   }
   free(current); /* Freeing node's memory */

   return 1;
}

int main(void) {
   Node *list;
   int value;

   create_list(&list); /* We could have avoid this function by using list == NULL */
   print_list(list);

   /* Inserting some values */
   insert(&list, 30);
   insert(&list, 7);
   insert(&list, 4);

   printf("After inserting values\n");
   print_list(list);

   /* Looking up some values */
   value = 30;

   /* Notice use of ?: (ternary operator) */
   printf("Found %d %s\n", value, find(list, value) ? "Yes": "No"); 
   value = 77;
   printf("Found %d %s\n", value, find(list, value) ? "Yes": "No"); 

   /* Deleting some values */
   delete(&list, 7);
   delete(&list, 30);
   delete(&list, 4);

   printf("After deleting values\n");
   print_list_recursive(list);

   return 0;
}

/* This space available for rent :) */
