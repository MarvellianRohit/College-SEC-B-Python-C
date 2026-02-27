#include <stdio.h>  // Standard I/O library for input and output functions
#include <stdlib.h> // Library for memory allocation (malloc) and process control

// Structure definition for a Node in the Singly Linked List
struct Node {
  int data;          // Field to store the numeric value
  struct Node *next; // Pointer to the next node in the sequence
};

// Global head pointer, initialized to NULL meaning the list is initially empty
struct Node *head = NULL;

// Function prototypes to inform the compiler about the functions defined later
void insertAtBeginning(int val);
void insertAtEnd(int val);
void insertAtPosition(int val, int pos);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition(int pos);
int countNodes();
void display();

int main() {
  int choice, val,
      pos; // Local variables for menu choice, input value, and position

  // Infinite loop for user menu interaction
  while (1) {
    printf("\n--- Singly Linked List Operations ---");
    printf("\n1. Insert at Beginning");
    printf("\n2. Insert at End");
    printf("\n3. Insert Position-wise");
    printf("\n4. Display & Count Nodes");
    printf("\n5. Delete at Beginning");
    printf("\n6. Delete at End");
    printf("\n7. Delete Position-wise");
    printf("\n8. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice); // Reading user's menu choice

    switch (choice) {
    case 1:
      printf("Enter value: ");
      scanf("%d", &val);
      insertAtBeginning(val); // Call function to insert at front
      break;
    case 2:
      printf("Enter value: ");
      scanf("%d", &val);
      insertAtEnd(val); // Call function to insert at back
      break;
    case 3:
      printf("Enter value: ");
      scanf("%d", &val);
      printf("Enter position: ");
      scanf("%d", &pos);
      insertAtPosition(val, pos); // Call function to insert at specific index
      break;
    case 4:
      display(); // Show all elements and total count
      break;
    case 5:
      deleteAtBeginning(); // Remove first node
      break;
    case 6:
      deleteAtEnd(); // Remove last node
      break;
    case 7:
      printf("Enter position: ");
      scanf("%d", &pos);
      deleteAtPosition(pos); // Remove node at specific index
      break;
    case 8:
      printf("Exiting...\n");
      exit(0); // Terminate the program execution
    default:
      printf("Invalid choice! Please try again.\n");
    }
  }
  return 0; // Return 0 to indicate successful program termination
}

// Function to insert a node at the very beginning of the list
void insertAtBeginning(int val) {
  // Allocate memory for a new node on the heap
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = val;  // Assign value to the node's data field
  newNode->next = head; // Point new node's next to the current head
  head = newNode;       // Update head to point to this new first node
  printf("Inserted %d at the beginning.\n", val);
}

// Function to insert a node at the end of the list
void insertAtEnd(int val) {
  // Creating the new node
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = val;
  newNode->next = NULL; // Since it's the last node, next must be NULL

  // If list is empty, make this new node the head
  if (head == NULL) {
    head = newNode;
    printf("Inserted %d as the first node.\n", val);
    return;
  }

  // Traverse to the last node
  struct Node *temp = head; // Start from head
  while (temp->next != NULL) {
    temp = temp->next; // Move to next node until we reach the end
  }
  temp->next = newNode; // Link the previous last node to our new node
  printf("Inserted %d at the end.\n", val);
}

// Function to insert a node at a user-defined position (1-based index)
void insertAtPosition(int val, int pos) {
  // If position is 1, it's same as inserting at beginning
  if (pos == 1) {
    insertAtBeginning(val);
    return;
  }

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = val;

  struct Node *temp = head;
  // Walk to the node just before the target position
  for (int i = 1; i < pos - 1 && temp != NULL; i++) {
    temp = temp->next;
  }

  // Checking if position is valid/within range
  if (temp == NULL) {
    printf("Invalid position!\n");
    free(newNode); // Free memory if position is unreachable
    return;
  }

  newNode->next = temp->next; // Link new node to the rest of the list
  temp->next = newNode;       // Link previous node to the new node
  printf("Inserted %d at position %d.\n", val, pos);
}

// Function to remove the first node from the list
void deleteAtBeginning() {
  // Check if list is already empty
  if (head == NULL) {
    printf("List is empty! Nothing to delete.\n");
    return;
  }
  struct Node *temp = head; // Keep reference to current head
  head = head->next;        // Move head to the second node
  free(temp);               // Deallocate memory of the old first node
  printf("Deleted node from the beginning.\n");
}

// Function to remove the last node from the list
void deleteAtEnd() {
  if (head == NULL) {
    printf("List is empty!\n");
    return;
  }

  // If only one node exists
  if (head->next == NULL) {
    free(head);
    head = NULL;
    printf("Deleted the last remaining node.\n");
    return;
  }

  // Traverse to find the second-to-last node
  struct Node *temp = head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  free(temp->next);  // Deallocate the last node
  temp->next = NULL; // Set the second-to-last node's next to NULL
  printf("Deleted node from the end.\n");
}

// Function to remove a node at a specific position (1-based index)
void deleteAtPosition(int pos) {
  if (head == NULL) {
    printf("List is empty!\n");
    return;
  }

  // Special case for first node deletion
  if (pos == 1) {
    deleteAtBeginning();
    return;
  }

  struct Node *temp = head;
  // Find the node before the one to be deleted
  for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
    temp = temp->next;
  }

  // Validation for range
  if (temp->next == NULL) {
    printf("Position out of bounds!\n");
    return;
  }

  struct Node *nodeToDelete = temp->next; // Temporarily store target node
  temp->next = nodeToDelete->next;        // Bypass the target node in the chain
  free(nodeToDelete);                     // Free memory
  printf("Deleted node at position %d.\n", pos);
}

// Utility function to calculate how many nodes are in the list
int countNodes() {
  int count = 0;            // Counter variable
  struct Node *temp = head; // Temporary pointer for traversal
  while (temp != NULL) {
    count++;           // Increment for each node found
    temp = temp->next; // Move forward
  }
  return count; // Return the final count
}

// Utility function to print all node data and the total count
void display() {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }
  struct Node *temp = head;
  printf("List Content: ");
  while (temp != NULL) {
    printf("%d -> ", temp->data); // Display current node's data
    temp = temp->next;            // Traverse to next
  }
  printf("NULL\n"); // Indicate the end of list
  printf("Total number of nodes: %d\n", countNodes()); // Show node count
}
