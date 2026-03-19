#include <stdio.h> // Include standard input/output library for printf and scanf
#include <stdlib.h> // Include standard library for memory allocation functions (malloc, free)

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

// Function to delete the first node (front) from the list
void delete_at_front() {
  struct dlinklist *temp; // Temporary pointer to hold the node to be deleted
  if (start == NULL) { // Check if the list is empty
    printf("\n List is empty."); // Print error message
    return; // Exit function since there's nothing to delete
  }
  temp = start; // Store the address of the first node in 'temp'
  start = start->next; // Update 'start' to point to the second node, effectively removing the first node from the sequence
  free(temp); // Free the dynamically allocated memory of the old first node
  printf("\n First node deleted."); // Confirm deletion to the user
}

// Function to delete at an intermediate position (middle)
void delete_at_pos() {
  struct dlinklist *temp, *prev; // 'temp' for the target node, 'prev' for the node before it
  int pos, ctr, nodectr = 0; // Variables for target position, loop counter, and total node count
  
  if (start == NULL) { // Check if the list is currently empty
    printf("\n List is empty."); // Inform the user
    return; // Exit function early
  }

  temp = start; // Initialize 'temp' to the first node to count total nodes
  while (temp != NULL) { // Traverse the entire list
    nodectr++; // Increment total node count for each node found
    temp = temp->next; // Move to the next node
  }

  printf("\n Enter position to delete: "); // Prompt the user for the position to delete
  scanf("%d", &pos); // Read the position into 'pos' variable

  if (pos > nodectr || pos < 1) { // Validate position (must be between 1 and total number of nodes)
    printf("\n Node does not exist"); // Print error if position is invalid
    return; // Exit function
  }

  if (pos == 1) { // If the chosen position is the first node
    delete_at_front(); // Use the dedicated function for front deletion
    return; // Exit function
  }

  if (pos > 1 && pos <= nodectr) { // If it's a valid position greater than 1
    temp = start; // Reset 'temp' to the front of the list
    prev = start; // Set 'prev' to the front of the list initially
    ctr = 1; // Start counter from position 1
    while (ctr < pos) { // Loop until the target position is reached
      prev = temp; // Keep track of the node just before the target node
      temp = temp->next; // Move 'temp' forward to the next node
      ctr = ctr + 1; // Increment current position counter
    }
    prev->next = temp->next; // Bypass the target node ('temp') by linking the previous node to the node after 'temp'
    free(temp); // Free the memory occupied by the target node
    printf("\n Node at position %d deleted.", pos); // Confirm successful deletion
  } else {
    printf("\n Invalid Operation."); // Fallback error message
  }
}

int main() {
  int ch, n; // Variables for menu choice 'ch' and number of nodes 'n'
  while (1) { // Infinite loop to keep showing the menu until 'Exit' is chosen
    printf("\n --- Singly Linked List Deletion Menu ---"); // Display menu title
    printf("\n 1. Create List"); // Option to create a new linked list
    printf("\n 2. Traverse List"); // Option to display the list elements
    printf("\n 3. Delete at Front"); // Option to delete the first node
    printf("\n 4. Delete at Position (Middle)"); // Option to delete at a specific position
    printf("\n 5. Exit"); // Option to exit the program
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
      delete_at_front(); // Call function to delete the head node
      break; 
    case 4: 
      delete_at_pos(); // Call function to delete a node at a particular index
      break; 
    case 5: 
      exit(0); // Exit the entire C program successfully
    default: 
      printf("\n Invalid choice!"); // Inform the user if the input does not match any menu option
    }
  }
  return 0; // Return 0 to indicate successful program execution to the OS
}
