#include <stdio.h> // Include standard input/output library for printf and scanf
#include <stdlib.h> // Include standard library for dynamic memory allocation (malloc, free)

// Structure definition for the linked list node
struct dlinklist { // Define a structure named 'dlinklist' to represent a node
  int data;               // Integer variable to store the actual data of the node
  struct dlinklist *next; // Pointer to the next node in the linked list
};

// Global pointer to the start of the list
struct dlinklist *start = NULL; // Initialize the global 'start' pointer to NULL, indicating an empty list

// Function to create and allocate memory for a new node
struct dlinklist *getnode() {
  struct dlinklist *newnode; // Declare a pointer for the new node
  newnode = (struct dlinklist *)malloc(sizeof(struct dlinklist)); // Dynamically allocate memory for one node
  if (newnode == NULL) { // Check if memory allocation failed
    printf("\n Memory allocation failed!"); // Print error message if malloc returns NULL
    return NULL; // Return NULL to indicate failure
  }
  printf("\n Enter data: "); // Prompt the user to enter data
  scanf("%d", &newnode->data); // Read user input and store it in the 'data' part of the node
  newnode->next = NULL; // Initialize 'next' pointer to NULL since the new node doesn't point to anything yet
  return newnode; // Return the address of the newly allocated and initialized node
}

// Function to traverse and print the contents of the list
void traverse() {
  struct dlinklist *temp; // Declare a temporary pointer to iterate through the list
  temp = start; // Start traversal from the first node
  printf("\n The contents of List: \n"); // Print heading
  if (start == NULL) { // Check if the list is completely empty
    printf("\n Empty List"); // Inform the user
    return; // Exit the function early
  }
  while (temp != NULL) { // Loop until the end of the list is reached (temp becomes NULL)
    printf(" %d-->", temp->data); // Print the data of the current node
    temp = temp->next; // Move 'temp' to point to the next node in the sequence
  }
  printf("NULL\n"); // Print 'NULL' to indicate the end of the linked list
}

// Function to create a list with n nodes initially
void createlist(int n) {
  int i; // Loop counter variable
  struct dlinklist *newnode, *temp; // Pointers for the new node and for traversing the list
  for (i = 0; i < n; i++) { // Loop to create 'n' nodes one by one
    newnode = getnode(); // Call getnode() to create a single node
    if (start == NULL) { // Check if this is the very first node being inserted
      start = newnode; // If list is empty, make 'start' point to this new node
    } else { // If the list already has nodes
      temp = start; // Start from the beginning to find the last node
      while (temp->next != NULL) // Loop until the last node (whose 'next' is NULL) is found
        temp = temp->next; // Move to the next node
      temp->next = newnode; // Attach the newly created node at the end of the list
    }
  }
}

// Function to reverse the ordering of nodes in the linked list in-place
void reverse_list() {
  struct dlinklist *prev = NULL, *current = start, *next = NULL; // Initialize three pointers to help reverse links

  if (start == NULL) { // Check if the linked list is empty
    printf("\n List is empty."); // Print error message
    return; // Exit function since there is nothing to reverse
  }

  while (current != NULL) { // Iterate through the list until the end is reached
    next = current->next;     // Temporarily store the next node before modifying the current node's link
    current->next = prev;     // Reverse the link by pointing the current node backwards to 'prev'
    prev = current;           // Shift 'prev' forward to become the current node for the next iteration
    current = next;           // Shift 'current' forward to process the next node in the original sequence
  }

  start = prev;               // Once the loop is done, 'prev' points to the new first node, so update 'start'
  printf("\n List reversed successfully."); // Confirm to the user that reversal is complete
}

int main() {
  int ch, n; // Variables for menu choice 'ch' and number of nodes 'n'
  while (1) { // Infinite loop to keep showing the menu until 'Exit' is chosen
    printf("\n --- Singly Linked List Reversal Menu ---"); // Display menu title
    printf("\n 1. Create List"); // Option to create a new linked list
    printf("\n 2. Traverse List"); // Option to display the list elements
    printf("\n 3. Reverse List"); // Option to reverse the existing items in the list
    printf("\n 4. Exit"); // Option to exit the program
    printf("\n Enter choice: "); // Prompt user to enter their choice
    scanf("%d", &ch); // Read the user's choice

    switch (ch) { // Switch-case block to handle the chosen menu option
    case 1:
      printf("\n Nodes to create: "); // Prompt for the number of initial nodes
      scanf("%d", &n); // Read the number of nodes
      createlist(n); // Call function to create the list with 'n' nodes
      break; // Break out of the switch block
    case 2: 
      traverse(); // Call traversal function to print the list
      break; 
    case 3: 
      reverse_list(); // Call function to reverse the list's node links
      break; 
    case 4: 
      exit(0); // Exit the entire C program successfully
    default: 
      printf("\n Invalid choice!"); // Inform the user if the input does not match any menu option
    }
  }
  return 0; // Return 0 to indicate successful program execution to the OS
}

/*
 --- Singly Linked List Reversal Menu ---
 1. Create List
 2. Traverse List
 3. Reverse List
 4. Exit
 Enter choice: 1
 Nodes to create: 3
 Enter data: 10
 Enter data: 20
 Enter data: 30
 
 --- Singly Linked List Reversal Menu ---
 1. Create List
 2. Traverse List
 3. Reverse List
 4. Exit
 Enter choice: 2
 The contents of List: 
 10--> 20--> 30-->NULL
 
 --- Singly Linked List Reversal Menu ---
 1. Create List
 2. Traverse List
 3. Reverse List
 4. Exit
 Enter choice: 3
 List reversed successfully.
 
 --- Singly Linked List Reversal Menu ---
 1. Create List
 2. Traverse List
 3. Reverse List
 4. Exit
 Enter choice: 2
 The contents of List: 
 30--> 20--> 10-->NULL
 
 --- Singly Linked List Reversal Menu ---
 1. Create List
 2. Traverse List
 3. Reverse List
 4. Exit
 Enter choice: 4
*/
