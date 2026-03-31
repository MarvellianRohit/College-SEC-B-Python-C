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

// Function to delete the last node (end) from the list
void delete_at_end() {
  struct dlinklist *temp, *prev; // Pointers for traversal and tracking previous node
  if (start == NULL) { // Check if the list is empty
    printf("\n List is empty."); // Print error message
    return; // Exit function since there's nothing to delete
  }
  temp = start; // Start traversal from the beginning
  if (temp->next == NULL) { // If there is only one node in the entire list
    free(temp); // Free the single node
    start = NULL; // Set start to NULL as the list is now completely empty
  } else { // If the list contains more than one node
    while (temp->next != NULL) { // Traverse precisely until the last node is reached
      prev = temp; // Keep track of the node directly preceding the last one
      temp = temp->next; // Progress 'temp' to the next subsequent node
    }
    prev->next = NULL; // Cut off the last node by making the second-to-last node the new end
    free(temp); // Permanently release the memory allocated to the final terminal node
  }
  printf("\n Last node deleted."); // Send confirmation indicating successful terminal deletion
}

// Function to delete a node at a given intermediate position (positionwise)
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

  printf("\n Enter position to delete: "); // Prompt the user for the exact positionwise deletion
  scanf("%d", &pos); // Read the targeted position into 'pos' variable

  if (pos > nodectr || pos < 1) { // Validate position (must be between 1 and total number of nodes)
    printf("\n Node does not exist"); // Print error if position is invalid
    return; // Exit function
  }

  if (pos == 1) { // If the chosen position is the very first node
    delete_at_front(); // Use the dedicated function for front deletion
    return; // Exit function
  }

  if (pos > 1 && pos <= nodectr) { // If it's a valid targeted position greater than 1
    temp = start; // Reset 'temp' to the front of the list
    prev = start; // Set 'prev' to the front of the list initially
    ctr = 1; // Start logical counter from baseline position 1
    while (ctr < pos) { // Ascend sequentially until the target coordinate position is exactly matched
      prev = temp; // Always capture the prior consecutive node just before advancing
      temp = temp->next; // Advance the foremost targeting probe one sequence unit forward
      ctr = ctr + 1; // Increment the logical synchronization counter value
    }
    prev->next = temp->next; // Create a bypass bridging precisely over the identified targeted positional node
    free(temp); // Discard the isolated dynamically designated memory cluster safely
    printf("\n Node at position %d deleted.", pos); // Issue localized confirmation of successful index deletion
  } else {
    printf("\n Invalid Operation."); // Fallback baseline error message catcher
  }
}

int main() {
  int ch, n; // Variables for menu choice 'ch' and number of nodes 'n'
  while (1) { // Infinite loop to keep showing the menu until 'Exit' is chosen
    printf("\n --- Singly Linked List Deletion Menu ---"); // Display logical menu title
    printf("\n 1. Create List"); // Option to instantiate and construct a new linked list sequence
    printf("\n 2. Traverse List"); // Option to visually sequentially render all existing elements
    printf("\n 3. Delete at Front"); // Option to exclusively strip away sequential starting head block
    printf("\n 4. Delete at End"); // Option to specifically snip off exactly precisely the furthest rear terminal component
    printf("\n 5. Delete Positionwise"); // Option to meticulously isolate and extract an element at an arbitrarily designated coordinate integer
    printf("\n 6. Exit"); // Execution halting instruction terminating total overarching continuous loop behavior
    printf("\n Enter choice: "); // Emit synchronous halt commanding explicit external configuration digit input
    scanf("%d", &ch); // Transcribe externally sourced string payload precisely to integer matrix registry standard

    switch (ch) { // Segregate specific control branches directly utilizing strict encoded categorical inputs
    case 1:
      printf("\n Nodes to create: "); // Deliver textual interrogative directive asking scalar quantitative definition
      scanf("%d", &n); // Intercept volume specification input mapping sequentially precisely into dedicated capacity integer
      createlist(n); // Channel numeric parameter payload forcefully downwards into initial constructive subsystem logic
      break; // Abort currently running consecutive conditional cascade flow instantly returning to macro shell layer
    case 2: 
      traverse(); // Direct processing pipeline downward completely into standalone diagnostic reading operational subroutine
      break; 
    case 3: 
      delete_at_front(); // Initiate strict localized top layer architectural de-allocation operational method payload directly
      break; 
    case 4: 
      delete_at_end(); // Launch highly precise deep rear tier segment dislodging processing mechanism explicitly
      break;
    case 5: 
      delete_at_pos(); // Transmit active operational vector down toward advanced granular mathematical selective filtering function logic
      break; 
    case 6: 
      exit(0); // Engage absolute application layer comprehensive thread annihilation systems ensuring complete program shutdown
    default: 
      printf("\n Invalid choice!"); // Distribute general catch-all feedback identifying unrecognized aberrant arbitrary input vectors cleanly
    }
  }
  return 0; // Transmit functional execution successful zeroed parameter return footprint upward to native OS host shell environment unconditionally
}

/*
 --- Singly Linked List Deletion Menu ---
 1. Create List
 2. Traverse List
 3. Delete at Front
 4. Delete at End
 5. Delete Positionwise
 6. Exit
 Enter choice: 1
 Nodes to create: 3
 Enter data: 10
 Enter data: 20
 Enter data: 30
 
 --- Singly Linked List Deletion Menu ---
 1. Create List
 2. Traverse List
 3. Delete at Front
 4. Delete at End
 5. Delete Positionwise
 6. Exit
 Enter choice: 2
 The contents of List: 
 10--> 20--> 30-->NULL
 
 --- Singly Linked List Deletion Menu ---
 1. Create List
 2. Traverse List
 3. Delete at Front
 4. Delete at End
 5. Delete Positionwise
 6. Exit
 Enter choice: 3
 First node deleted.
 
 --- Singly Linked List Deletion Menu ---
 1. Create List
 2. Traverse List
 3. Delete at Front
 4. Delete at End
 5. Delete Positionwise
 6. Exit
 Enter choice: 2
 The contents of List: 
 20--> 30-->NULL
 
 --- Singly Linked List Deletion Menu ---
 1. Create List
 2. Traverse List
 3. Delete at Front
 4. Delete at End
 5. Delete Positionwise
 6. Exit
 Enter choice: 4
 Last node deleted.
 
 --- Singly Linked List Deletion Menu ---
 1. Create List
 2. Traverse List
 3. Delete at Front
 4. Delete at End
 5. Delete Positionwise
 6. Exit
 Enter choice: 2
 The contents of List: 
 20-->NULL
 
 --- Singly Linked List Deletion Menu ---
 1. Create List
 2. Traverse List
 3. Delete at Front
 4. Delete at End
 5. Delete Positionwise
 6. Exit
 Enter choice: 1
 Nodes to create: 2
 Enter data: 40
 Enter data: 50
 
 --- Singly Linked List Deletion Menu ---
 1. Create List
 2. Traverse List
 3. Delete at Front
 4. Delete at End
 5. Delete Positionwise
 6. Exit
 Enter choice: 2
 The contents of List: 
 20--> 40--> 50-->NULL
 
 --- Singly Linked List Deletion Menu ---
 1. Create List
 2. Traverse List
 3. Delete at Front
 4. Delete at End
 5. Delete Positionwise
 6. Exit
 Enter choice: 5
 Enter position to delete: 2
 Node at position 2 deleted.
 
 --- Singly Linked List Deletion Menu ---
 1. Create List
 2. Traverse List
 3. Delete at Front
 4. Delete at End
 5. Delete Positionwise
 6. Exit
 Enter choice: 2
 The contents of List: 
 20--> 50-->NULL
 
 --- Singly Linked List Deletion Menu ---
 1. Create List
 2. Traverse List
 3. Delete at Front
 4. Delete at End
 5. Delete Positionwise
 6. Exit
 Enter choice: 6
*/
