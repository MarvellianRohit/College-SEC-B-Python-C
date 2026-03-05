#include <stdio.h>
#include <stdlib.h>

// Structure definition for the linked list node
// Note: Named 'dlinklist' but structure implies singly linked list (only 'next'
// pointer)
struct dlinklist {
  int data;               // Data of the node
  struct dlinklist *next; // Pointer to the next node
};

// Global pointer to the start of the list
struct dlinklist *start = NULL;

// Function to create and allocate memory for a new node
struct dlinklist *getnode() {
  struct dlinklist *newnode;
  // Allocate memory
  newnode = (struct dlinklist *)malloc(sizeof(struct dlinklist));
  printf("\n Enter data: ");
  // Input data
  scanf("%d", &newnode->data);
  newnode->next = NULL; // Initialize next to NULL
  return newnode;
}

// Function to traverse and print the contents of the list
void traverse() {
  struct dlinklist *temp;
  temp = start;
  printf("\n The contents of List (Left to Right): \n\n");

  // Check if list is empty
  if (start == NULL) {
    printf("\n Empty List");
    return;
  } else {
    // Iterate through the list until end
    while (temp != NULL) {
      printf(" %d-->", temp->data);
      temp = temp->next; // Move to next node
    }
  }
  printf("NULL");
}

// Function to create a list with n nodes initially
void createlist(int n) {
  int i;
  struct dlinklist *newnode;
  struct dlinklist *temp;

  for (i = 0; i < n; i++) {
    newnode = getnode(); // Create a new node

    if (start == NULL) {
      // If list is empty, make new node the start
      start = newnode;
    } else {
      // Otherwise, traverse to the end and append
      temp = start;
      while (temp->next != NULL)
        temp = temp->next;
      temp->next = newnode;
    }
  }
}

// Function to insert a node at the end of the existing list
void insert_at_end() {
  struct dlinklist *newnode, *temp;
  printf(" This is for new struct dlinklist at the end");
  newnode = getnode(); // Create new node to insert

  if (start == NULL) {
    // If list is empty, new node becomes start
    start = newnode;
  } else {
    // Traverse to the last node
    temp = start;
    while (temp->next != NULL)
      temp = temp->next;
    // Point the last node's next to the new node
    temp->next = newnode;
  }
}

// Function to delete the last node of the list
void delete_at_end() {
  struct dlinklist *temp, *prev;

  if (start == NULL) {
    printf("\n Empty List. Nothing to delete.");
    return;
  }

  temp = start;
  if (temp->next == NULL) {
    // Only one node in the list
    free(temp);
    start = NULL;
    printf("\n Last node deleted. List is now empty.");
    return;
  }

  // Traverse to the end while keeping track of the previous node
  while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }

  prev->next = NULL; // Disconnect the last node
  free(temp);        // Deallocate memory
  printf("\n Last node deleted.");
}

int main() {
  int ch, n;

  while (1) {
    printf("\n\n --- Linked List Menu ---");
    printf("\n 1. Create List");
    printf("\n 2. Traverse List");
    printf("\n 3. Insert at End");
    printf("\n 4. Delete at End");
    printf("\n 5. Exit");
    printf("\n Enter your choice: ");
    scanf("%d", &ch);

    switch (ch) {
    case 1:
      if (start == NULL) {
        printf("\n Number of nodes you want to create: ");
        scanf("%d", &n);
        createlist(n);
        printf("\n List created..");
      } else {
        printf("\n List is already created..");
      }
      break;
    case 2:
      traverse();
      break;
    case 3:
      insert_at_end();
      break;
    case 4:
      delete_at_end();
      break;
    case 5:
      printf("\n Exiting...");
      exit(0);
    default:
      printf("\n Invalid choice! Try again.");
    }
  }
  return 0;
}
/*
Output:
Execution timed out (possibly waiting for input).*/
