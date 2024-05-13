#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int data;
   struct node *next;   
} Node;

void create_list(Node **head);
void print_list(Node *head);
int wrong_insert(Node *head, int new_value);

void create_list(Node **head) {
   *head = NULL;
}

void print_list(Node *head) {
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

/* This function does not insert the value */
int wrong_insert(Node *head, int new_value) {
   Node *current = head, *prev = NULL, *new_item;

   while (current != NULL && new_value > current->data) {
      prev = current;
      current = current->next;
   }

   new_item = malloc(sizeof(*new_item));
   if (new_item == NULL) {
      return 0;
   }
   new_item->data = new_value;
   new_item->next = current;
   if (prev == NULL) {
      head = new_item;
   } else {
      prev->next = new_item;
   }

   return 1;
}

int main(void) {
   Node *head;

   create_list(&head);
   print_list(head);

   /* Inserting some values */
   wrong_insert(head, 30);
   wrong_insert(head, 7);
   wrong_insert(head, 4);
   printf("After inserting values\n");
   print_list(head);

   return 0;
}
