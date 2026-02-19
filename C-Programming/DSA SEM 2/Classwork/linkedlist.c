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

int main() {
  int ch, n;

  // Check if list is not already created
  if (start == NULL) {
    printf("\n Number of nodes you want to create: ");
    scanf("%d", &n);
    createlist(n); // Create initial list
    printf("\n List created..\n");
    insert_at_end(); // Insert an additional node at the end
  } else {
    printf("\n List is already created..");
  }
  traverse(); // Display the list
  return 0;
}