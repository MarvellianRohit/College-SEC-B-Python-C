#include <stdio.h>  // Standard input-output library
#include <stdlib.h> // Library for dynamic memory allocation

// Node structure definition
struct Node {
  int data;          // Integer data part of the node
  struct Node *next; // Pointer addressing the next node in the list
};

// Function prototypes
struct Node *createList(int n);
struct Node *reverseList(struct Node *head);
void displayList(struct Node *head);

int main() {
  int n;                    // Variable to store number of nodes to create
  struct Node *head = NULL; // Initial list head

  printf("Enter the number of nodes to create: ");
  scanf("%d", &n); // Read user input for list size

  // If n is zero or negative, handle gracefully
  if (n <= 0) {
    printf("Invalid number of nodes.\n");
    return 0;
  }

  // Step 1: Create the linked list
  head = createList(n);

  // Step 2: Display list before reversing
  printf("\nList before reverse:\n");
  displayList(head);

  // Step 3: Reverse the list
  head = reverseList(head);

  // Step 4: Display list after reversing
  printf("\nList after reverse:\n");
  displayList(head);

  return 0; // Success
}

// Function to create a linked list with 'n' elements
struct Node *createList(int n) {
  struct Node *head = NULL, *temp = NULL, *newNode = NULL;
  int val;

  for (int i = 1; i <= n; i++) {
    // Allocate memory for each new node
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data for node %d: ", i);
    scanf("%d", &val);    // Get node data from user
    newNode->data = val;  // Store data
    newNode->next = NULL; // Set default next to NULL

    if (head == NULL) {
      // First node becomes the head
      head = newNode;
      temp = head; // 'temp' follows the pointer chain
    } else {
      // Successive nodes are linked to the tail
      temp->next = newNode;
      temp = temp->next; // Move tail pointer forward
    }
  }
  return head; // Return the head of the newly created list
}

// Function to reverse the linked list using iterative method
struct Node *reverseList(struct Node *head) {
  struct Node *prev = NULL, *current = head, *next = NULL;

  // Iterate through the entire list
  while (current != NULL) {
    next = current->next; // Temporarily save the next node
    current->next = prev; // Reverse the link: current now points backwards
    prev = current;       // Move 'prev' one step forward
    current = next;       // Move 'current' one step forward
  }
  // Loop ends when 'current' is NULL, 'prev' will be at the new first node
  return prev; // Return the new head of the reversed list
}

// Function to display all nodes in the list
void displayList(struct Node *head) {
  struct Node *temp = head; // Start traversal from the head node

  if (temp == NULL) {
    printf("The list is empty.\n");
    return;
  }

  // Iterate until the end of the list
  while (temp != NULL) {
    printf("%d -> ", temp->data); // Print node value
    temp = temp->next;            // Advance to the next node
  }
  printf("NULL\n"); // End marker
}
