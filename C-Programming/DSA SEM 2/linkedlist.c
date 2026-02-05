// Standard input/output library for printf and scanf functions
#include <stdio.h>

// Standard library for memory allocation functions like malloc
#include <stdlib.h>

// Structure definition for a singly linked list node
struct slinklist {
  int data;               // Data field to store integer value
  struct slinklist *next; // Pointer to the next node in the list
};

// Global pointer to the start/head of the linked list
// Initialized to NULL indicating an empty list
struct slinklist *start = NULL;

// Function to create and return a new node
// This function allocates memory for a new node, takes user input, and returns
// the node
struct slinklist *getnode() {
  struct slinklist *newnode; // Declare a pointer for the new node

  // Allocate memory for the new node using malloc
  // sizeof(struct slinklist) ensures correct amount of memory is allocated
  newnode = (struct slinklist *)malloc(sizeof(struct slinklist));

  // Prompt user to enter data for the node
  printf("\nEnter the data: ");

  // Read the integer data from user and store it in the data field
  // &newnode->data gives the address of the data field
  scanf("%d", &newnode->data);

  // Initialize the next pointer to NULL
  // This makes the new node the last node (no successor)
  newnode->next = NULL;

  // Return the address of the newly created node
  return newnode;
}

// Function to traverse and display all elements in the linked list
void traverse() {
  struct slinklist *temp; // Temporary pointer for traversal

  // Note: Bug in original code - temp should be initialized to start
  // temp = start; should be added here

  // Loop continues until we reach the end of the list (NULL)
  while (temp != NULL) {
    // Print the data of the current node
    printf("%d ", temp->data);

    // Move to the next node in the list
    temp = temp->next;
  }
}
