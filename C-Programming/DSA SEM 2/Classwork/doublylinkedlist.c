#include <stdio.h>   // include standard input/output library for printf, scanf
#include <stdlib.h>  // include standard library for malloc (memory allocation)

// Define the structure for a doubly linked list node
struct dlinklist {
  struct dlinklist *left;   // pointer to the previous node (left/back link)
  int data;                 // stores the integer value of the node
  struct dlinklist *right;  // pointer to the next node (right/forward link)
};

struct dlinklist *start = NULL;  // global pointer to the first node; NULL means list is empty

// Function to create and return a new node with user-entered data
struct dlinklist *getnode() {
  struct dlinklist *newnode;                                      // declare a pointer for the new node
  newnode = (struct dlinklist *)malloc(sizeof(struct dlinklist)); // allocate memory for the new node
  printf("Enter Data: ");                                         // prompt user to enter a value
  scanf("%d", &newnode->data);                                    // read integer input and store in node's data field
  newnode->left = NULL;                                           // set left pointer to NULL (no previous node yet)
  newnode->right = NULL;                                          // set right pointer to NULL (no next node yet)
  return newnode;                                                 // return the newly created node
};

// Insert a new node at the beginning of the doubly linked list
void insertAtBeginning() {
  struct dlinklist *newnode;                              // declare pointer for the new node
  printf("\nInfo for insertion at the beginning: ");     // prompt user for node data
  newnode = getnode();                                    // create a new node with user input

  if (start == NULL) {                                   // check if the list is currently empty
    // List is empty, new node becomes the only node
    start = newnode;                                     // new node is the only node, so it becomes start
  } else {
    // Link new node to the current first node
    newnode->right = start; // new node points forward to old first node
    start->left = newnode;  // old first node points back to new node
    start = newnode;        // update start to new node
  }
  printf("Node inserted at the beginning.\n");           // confirm insertion to user
}

// Insert a new node at the end of the doubly linked list
void insertAtEnd() {
  struct dlinklist *newnode, *temp;               // declare pointers: newnode for new node, temp for traversal
  printf("\nInfo for insertion at the end: ");    // prompt user for node data
  newnode = getnode();                            // create a new node with user input

  if (start == NULL) {                            // check if the list is currently empty
    // List is empty, new node becomes the only node
    start = newnode;                              // new node is the only node, so it becomes start
  } else {
    // Traverse to the last node
    temp = start;                                 // start traversal from the first node
    while (temp->right != NULL) {                 // keep moving right until the last node is reached
      temp = temp->right;                         // move temp to the next node
    }
    // Link new node after the last node
    temp->right = newnode;   // last node points forward to new node
    newnode->left = temp;    // new node points back to last node
  }
  printf("Node inserted at the end.\n");          // confirm insertion to user
}

// Insert a new node at an intermediate (middle) position in the doubly linked list
void insertAtIntermediate() {
  struct dlinklist *newnode, *temp;          // newnode: node to insert; temp: traversal pointer
  int pos, i;                               // pos: target position; i: loop counter

  printf("\nInfo for insertion at intermediate position: ");
  newnode = getnode();                       // create a new node with user input

  printf("Enter position to insert (1-based): ");
  scanf("%d", &pos);                         // read the desired position from the user

  if (pos <= 1 || start == NULL) {           // if position is 1 or list is empty, insert at beginning
    newnode->right = start;                  // new node points forward to old first node
    if (start != NULL)
      start->left = newnode;                 // old first node points back to new node
    start = newnode;                         // update start to new node
    printf("Node inserted at position 1 (beginning).\n");
    return;
  }

  // Traverse to the (pos-1)th node
  temp = start;                              // begin from the first node
  for (i = 1; i < pos - 1 && temp->right != NULL; i++) {
    temp = temp->right;                      // move to the next node
  }

  // Now temp points to the node just before the target position
  newnode->right = temp->right;              // new node's right points to the node currently at pos
  newnode->left  = temp;                     // new node's left points back to the (pos-1)th node

  if (temp->right != NULL) {                 // if there is a node after the insertion point
    temp->right->left = newnode;             // that node's left pointer now points to new node
  }

  temp->right = newnode;                     // (pos-1)th node's right pointer now points to new node
  printf("Node inserted at position %d.\n", pos); // confirm insertion to user
}

// Function to display all nodes in the list from left to right
void traverse() {
  struct dlinklist *temp;                          // declare a temp pointer for traversal
  temp = start;                                    // start from the first node
  printf("The content of the List are: ");         // print heading
  if (start == NULL) {                             // check if the list is empty
    printf("Empty List");                          // inform user the list has no nodes
  } else {
    while (temp != NULL) {                         // loop through each node until end of list
      printf("%d ", temp->data);                   // print the data of the current node
      temp = temp->right;                          // move to the next node using right pointer
    }
  }
}

// Function to create a linked list of n nodes
void createlist(int n) {
  int i;                          // loop counter
  struct dlinklist *newnode;      // pointer to hold each new node
  struct dlinklist *temp;         // pointer used for traversal
  for (i = 0; i < n; i++) {      // repeat n times to insert n nodes
    newnode = getnode();          // create a new node with user input
    if (start == NULL) {          // if the list is empty
      start = newnode;            // first node becomes start
    } else {
      temp = start;               // begin traversal from start
      while (temp->right != NULL) { // traverse to the last node
        temp = temp->right;

        temp->right = newnode;    // attach new node at the end
        newnode->left = temp;     // set back link of new node to previous last node
      }
    }
  }
}

int main() {
  int n;                                            // variable to store number of nodes
  printf("Enter the number of nodes: ");            // prompt user for number of nodes
  scanf("%d", &n);                                  // read the number of nodes
  createlist(n);                                    // create the doubly linked list with n nodes

  printf("\nInserting a node at the beginning:\n"); // inform user about next operation
  insertAtBeginning();                              // insert a new node at the beginning

  printf("\nList after insertion at beginning:\n"); // heading for list display
  traverse();                                       // display the updated list

  printf("\nInserting a node at the end:\n");              // inform user about next operation
  insertAtEnd();                                         // insert a new node at the end

  printf("\nList after insertion at end:\n");             // heading for list display
  traverse();                                            // display the updated list

  printf("\nInserting a node at an intermediate position:\n"); // inform user about next operation
  insertAtIntermediate();                                // insert a new node at a user-specified position

  printf("\nList after insertion at intermediate position:\n"); // heading for list display
  traverse();                                            // display the final list

  return 0;                                              // indicate successful program termination
}

/*
Output:
Enter the number of nodes: Enter Data: Enter Data: Enter Data: Enter Data: Enter Data: Enter Data: Enter Data: Enter Data: Enter Data: Enter Data: 
Inserting a node at the beginning:

Info for insertion at the beginning: Enter Data: Node inserted at the beginning.

List after insertion at beginning:
The content of the List are: 0 20 
Inserting a node at the end:

Info for insertion at the end: Enter Data: Node inserted at the end.

List after insertion at end:
The content of the List are: 0 20 0 
Inserting a node at an intermediate position:

Info for insertion at intermediate position: Enter Data: Enter position to insert (1-based): Node inserted at position 1 (beginning).

List after insertion at intermediate position:
The content of the List are: 0 0 20 0
*/
