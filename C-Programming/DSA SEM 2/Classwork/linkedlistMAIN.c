#include <stdio.h>
#include <stdlib.h>


// Structure definition for the linked list node

struct dlinklist {
  int data;               // Data of the node

  struct dlinklist *next; // Pointer to the next node

};


// Global pointer to the start of the list

struct dlinklist *start = NULL;


// Function to create and allocate memory for a new node

struct dlinklist *getnode() {
  struct dlinklist *newnode;

  newnode = (struct dlinklist *)malloc(sizeof(struct dlinklist));

  if (newnode == NULL) {
    printf("\n Memory allocation failed!");

    return NULL;

  }

  printf("\n Enter data: ");

  scanf("%d", &newnode->data);

  newnode->next = NULL;

  return newnode;

}


// Function to count the total number of nodes in the linked list

int count_nodes() {
  int cnt = 0; // Initialize counter to 0

  struct dlinklist *temp = start; // Start traversing from the first node

  while (temp != NULL) { // Continue until the end of the list is reached
    cnt++; // Increment the counter for each node found
    temp = temp->next; // Move to the next node in the list

  }

  return cnt; // Return the final count of nodes

}


// Function to traverse and print the contents of the list

void traverse() {
  struct dlinklist *temp;

  temp = start;

  printf("\n The contents of List: \n");

  if (start == NULL) {
    printf("\n Empty List");

    return;

  }

  while (temp != NULL) {
    printf(" %d-->", temp->data);

    temp = temp->next;

  }

  printf("NULL\n");

}


// Function to create a list with n nodes initially

void createlist(int n) {
  int i;

  struct dlinklist *newnode, *temp;

  for (i = 0; i < n; i++) {
    newnode = getnode();

    if (start == NULL) {
      start = newnode;

    } else {
      temp = start;

      while (temp->next != NULL)
        temp = temp->next;

      temp->next = newnode;

    }

  }

}


// Function to insert a new node at the beginning (front) of the list

void insert_at_front() {
  struct dlinklist *newnode; // Pointer for the new node to be created

  newnode = getnode(); // Allocate memory and get data for the new node

  if (newnode == NULL) return; // Exit if memory allocation failed

  newnode->next = start; // Point the new node's next to the current first node

  start = newnode; // Update the start pointer to the new node

  printf("\n Node inserted at the beginning."); // Confirm insertion

}


// Function to insert a new node at the end (rear) of the list

void insert_at_end() {
  struct dlinklist *newnode, *temp; // Pointers for the new node and traversal

  newnode = getnode(); // Create and initialize the new node

  if (newnode == NULL) return; // Error check for memory

  if (start == NULL) { // If the list is currently empty
    start = newnode; // The new node becomes the first node

  } else {
    temp = start; // Start at the beginning to find the last node

    while (temp->next != NULL) // Loop until the last node is reached
      temp = temp->next; // Move to the next node

    temp->next = newnode; // Link the last node's next to the new node

  }

  printf("\n Node inserted at the end."); // Confirm insertion

}


// Function to insert a new node at a specific intermediate position

void insert_at_pos() {
  struct dlinklist *newnode, *temp; // Pointers for the new node and traversal
  int pos, i, n; // Variables for position, loop counter, and node count

  n = count_nodes(); // Get current total nodes for position validation

  printf("\n Enter position (1 to %d): ", n + 1); // Prompt user for position
  scanf("%d", &pos); // Read the desired position

  if (pos < 1 || pos > n + 1) { // Validate if the position is within bounds
    printf("\n Invalid position!"); // Print error message

    return; // Exit function

  }

  if (pos == 1) { // If the position is 1, call the front insertion function
    insert_at_front(); 

    return;

  }

  newnode = getnode(); // Create the new node to insert

  if (newnode == NULL) return; // Exit if allocation fails

  temp = start; // Start traversal from the beginning

  for (i = 1; i < pos - 1; i++) { // Navigate to the node just before the insertion position
    temp = temp->next; // Move to the next node

  }

  newnode->next = temp->next; // Point new node's next to the current node at this position

  temp->next = newnode; // Update previous node's next to the new node

  printf("\n Node inserted at position %d.", pos); // Confirm insertion

}


// Function to delete the first node (front) from the list

void delete_at_front() {
  struct dlinklist *temp; // Temporary pointer to store the node to be freed

  if (start == NULL) { // Check if the list is empty
    printf("\n List is empty."); // Inform the user
    return; // Exit function

  }

  temp = start; // Save the address of the first node

  start = start->next; // Move the start pointer to the second node

  free(temp); // Deallocate memory of the old first node

  printf("\n First node deleted."); // Confirm deletion

}


// Function to delete the last node (end) of the list

void delete_at_end() {
  struct dlinklist *temp, *prev; // Pointers for traversal and tracking previous node

  if (start == NULL) { // If list is already empty
    printf("\n List is empty."); // Inform user
    return; // Exit

  }

  temp = start; // Start at the beginning

  if (temp->next == NULL) { // If there is only one node in the list
    free(temp); // Free that node

    start = NULL; // List is now empty

  } else {
    while (temp->next != NULL) { // Traverse to find the very last node
      prev = temp; // Keep track of the second-to-last node

      temp = temp->next; // Move to the next node

    }

    prev->next = NULL; // Make the second-to-last node the new end

    free(temp); // Deallocate the memory of the last node

  }

  printf("\n Last node deleted."); // Confirm deletion

}


// Function to delete at an intermediate position (following the algorithm steps)

void delete_at_pos() {
  struct dlinklist *temp, *prev; // Pointers for current and previous nodes
  int pos, ctr, nodectr = 0; // Local counter and position variables

  if (start == NULL) { // Check if list is empty
    printf("\n List is empty."); // Error message

    return; // Exit

  }

  // Initially count total nodes for validation

  temp = start; // Start from first node

  while (temp != NULL) { // Traverse whole list
    nodectr++; // Increment node counter

    temp = temp->next; // Move next

  }

  printf("\n Enter position to delete: "); // Prompt for position
  scanf("%d", &pos); // Read user input

  // Step 5: If pos > nodectr

  if (pos > nodectr || pos < 1) { // Validate if position exists
    printf("\n Node does not exist"); // Message as per algorithm

    return; // Exit

  }

  // If pos is 1, use the delete_at_front specialized function

  if (pos == 1) { // Case for deleting the first node
    delete_at_front(); // Call front deletion function

    return; // Exit

  }

  // Step 6: If pos > 1 AND pos <= nodectr

  // (Handling intermediate and last positions following Step 7-10)

  if (pos > 1 && pos <= nodectr) { 

    // Step 7: Set temp = start, prev = start, ctr = 1

    temp = start; // Initialize temp to start

    prev = start; // Initialize prev to start

    ctr = 1; // Initialize counter to 1

    // Step 8: While ctr < pos

    while (ctr < pos) { // Loop until the target position is reached
      prev = temp; // Update prev to current node

      temp = temp->next; // Move temp to the next node

      ctr = ctr + 1; // Increment step counter

    }

    // Step 9: Set prev->next = temp->next

    prev->next = temp->next; // Link previous node to the node after temp

    // Step 10: Set free(temp)

    free(temp); // Deallocate memory of the target node

    printf("\n Node at position %d deleted.", pos); // Confirm deletion

  } else {

    // Step 11: Else

    printf("\n Invalid Operation."); // Fallback error

  }

}


// Function to search for a specific value in the linked list

void search_node() {
  struct dlinklist *temp = start; // Temporary pointer for traversal
  int target, pos = 1, found = 0; // Target value, position tracker, and status flag

  if (start == NULL) { // Check if the list is empty
    printf("\n List is empty."); // Inform user
    return; // Exit

  }

  printf("\n Enter value to search: "); // Prompt user for value
  scanf("%d", &target); // Read the target value

  while (temp != NULL) { // Iterate through each node in the list
    if (temp->data == target) { // Compare node data with target value
      printf("\n Value %d found at position %d.", target, pos); // Report location

      found = 1; // Mark as found

      break; // Exit loop early

    }

    temp = temp->next; // Move to the next node

    pos++; // Increment position counter

  }

  if (!found) { // If the loop finished without finding the target
    printf("\n Value %d not found in the list.", target); // Inform user
  }

}


// Function to reverse the ordering of nodes in the linked list in-place

void reverse_list() {
  struct dlinklist *prev = NULL, *current = start, *next = NULL; // Three pointers for manipulation

  if (start == NULL) { // Check if list is empty
    printf("\n List is empty."); // Inform user
    return; // Exit

  }

  while (current != NULL) { // Traverse the entire list
    next = current->next;    // Temporarily store address of the next node

    current->next = prev;     // Change current node's pointer to the previous node

    prev = current;           // Move 'prev' one step forward to current node
    current = next;           // Move 'current' one step forward to next node
  }

  start = prev;               // Reset the start pointer to the new first node (formerly last)
  printf("\n List reversed successfully."); // Confirm reversal

}


int main() {
  int ch, n; // Variables for user choice and initial node count

  while (1) { // Infinite loop for the menu system
    printf("\n --- Singly Linked List Menu ---");

    printf("\n 1. Create List");

    printf("\n 2. Traverse List");

    printf("\n 3. Insert at Front");

    printf("\n 4. Insert at End");

    printf("\n 5. Insert at Position");

    printf("\n 6. Delete at Front");

    printf("\n 7. Delete at End");

    printf("\n 8. Delete at Position");

    printf("\n 9. Count Nodes");

    printf("\n 10. Search Node");

    printf("\n 11. Reverse List");

    printf("\n 12. Exit");

    printf("\n Enter choice: ");

    scanf("%d", &ch); // Read user menu choice

    switch (ch) { // Handle different menu options
    case 1:
      printf("\n Nodes to create: ");

      scanf("%d", &n);

      createlist(n); // Create initial list

      break;

    case 2: traverse(); break; // Display list contents

    case 3: insert_at_front(); break; // Insert node at start

    case 4: insert_at_end(); break; // Insert node at end

    case 5: insert_at_pos(); break; // Insert node at specific index
    case 6: delete_at_front(); break; // Remove first node

    case 7: delete_at_end(); break; // Remove last node

    case 8: delete_at_pos(); break; // Remove node at specific index
    case 9: printf("\n Total Nodes: %d", count_nodes()); break; // Print node count

    case 10: search_node(); break; // Find value in list

    case 11: reverse_list(); break; // Flip list order

    case 12: exit(0); // Exit program

    default: printf("\n Invalid choice!"); // Handle unknown options

    }

  }

  return 0; // Return success code

}

/*
Output:

 --- Singly Linked List Menu ---
 1. Create List
 2. Traverse List
 3. Insert at Front
 4. Insert at End
 5. Insert at Position
 6. Delete at Front
 7. Delete at End
 8. Delete at Position
 9. Count Nodes
 10. Search Node
 11. Reverse List
 12. Exit
 Enter choice: 
 Nodes to create: 
 Enter data: 
 Enter data: 
 Enter data: 
 --- Singly Linked List Menu ---
 1. Create List
 2. Traverse List
 3. Insert at Front
 4. Insert at End
 5. Insert at Position
 6. Delete at Front
 7. Delete at End
 8. Delete at Position
 9. Count Nodes
 10. Search Node
 11. Reverse List
 12. Exit
 Enter choice: 
 The contents of List: 
 10--> 20--> 30-->NULL

 --- Singly Linked List Menu ---
 1. Create List
 2. Traverse List
 3. Insert at Front
 4. Insert at End
 5. Insert at Position
 6. Delete at Front
 7. Delete at End
 8. Delete at Position
 9. Count Nodes
 10. Search Node
 11. Reverse List
 12. Exit
 Enter choice: 
 Enter data: 
 Node inserted at the beginning.
 --- Singly Linked List Menu ---
 1. Create List
 2. Traverse List
 3. Insert at Front
 4. Insert at End
 5. Insert at Position
 6. Delete at Front
 7. Delete at End
 8. Delete at Position
 9. Count Nodes
 10. Search Node
 11. Reverse List
 12. Exit
 Enter choice: 
 The contents of List: 
 10--> 10--> 20--> 30-->NULL

 --- Singly Linked List Menu ---
 1. Create List
 2. Traverse List
 3. Insert at Front
 4. Insert at End
 5. Insert at Position
 6. Delete at Front
 7. Delete at End
 8. Delete at Position
 9. Count Nodes
 10. Search Node
 11. Reverse List
 12. Exit
 Enter choice: 
 Total Nodes: 4
 --- Singly Linked List Menu ---
 1. Create List
 2. Traverse List
 3. Insert at Front
 4. Insert at End
 5. Insert at Position
 6. Delete at Front
 7. Delete at End
 8. Delete at Position
 9. Count Nodes
 10. Search Node
 11. Reverse List
 12. Exit
 Enter choice:
*/
