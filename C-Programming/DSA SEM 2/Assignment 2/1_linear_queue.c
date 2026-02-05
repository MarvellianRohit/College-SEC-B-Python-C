#include <stdio.h> // Include standard input-output library for printf and scanf
#include <stdlib.h> // Include standard library for exit() function

#define MAX                                                                    \
  10 // Define a constant macro MAX with value 10, representing the maximum size
     // of the queue

int queue[MAX]; // Declare an integer array 'queue' of size MAX (10) to store
                // queue elements
int front =
    -1; // Initialize 'front' to -1, indicating the queue is initially empty
int rear =
    -1; // Initialize 'rear' to -1, indicating the queue is initially empty

// Function prototypes to declare functions before they are used
void enqueue(int data);
void dequeue();
void display();
void peek();

int main() {
  int choice, value; // Declare variables to store user choice and the value to
                     // be enqueued

  // Start an infinite loop to continuously show the menu until the user chooses
  // to exit
  while (1) {
    printf("\n*** Linear Queue Menu ***\n"); // Print menu header
    printf("1. Enqueue\n");                  // Option to add an element
    printf("2. Dequeue\n");                  // Option to remove an element
    printf("3. Display\n");                  // Option to show all elements
    printf("4. Peek\n");                     // Option to see the front element
    printf("5. Exit\n");                     // Option to exit the program
    printf("Enter your choice: ");           // Prompt user for input
    scanf("%d", &choice); // Read user input and store it in 'choice'

    // Switch statement to execute code based on the user's choice
    switch (choice) {
    case 1:
      printf("Enter value to enqueue: "); // Prompt for value to add
      scanf("%d", &value);                // Read the value
      enqueue(value); // Call enqueue function with the value
      break;          // Break out of the switch case
    case 2:
      dequeue(); // Call dequeue function to remove an element
      break;     // Break out of the switch case
    case 3:
      display(); // Call display function to show queue
      break;     // Break out of the switch case
    case 4:
      peek(); // Call peek function to see front element
      break;  // Break out of the switch case
    case 5:
      printf("Exiting...\n"); // Print exit message
      exit(0);                // Terminate the program successfully
    default:
      printf("Invalid choice! Please try again.\n"); // Handle invalid input
    }
  }
  return 0; // Return 0 to indicate successful execution (though loop is
            // infinite/exited via exit(0))
}

// Function to add an element to the queue
void enqueue(int data) {
  if (rear == MAX - 1) { // Check if the queue is full (Overflow condition)
    printf("\nQueue Overflow! Cannot enqueue %d.\n",
           data); // Print error if full
  } else {
    if (front == -1) { // Check if this is the first element being added
      front = 0;       // If so, set front to 0 (start of queue)
    }
    rear++; // Increment rear to point to the next available position
    queue[rear] = data; // Store the data at the new rear position
    printf("\nEnqueued %d into queue.\n", data); // Confirm insertion
  }
}

// Function to remove an element from the queue
void dequeue() {
  if (front == -1 ||
      front > rear) { // Check if queue is empty (Underflow condition)
    printf("\nQueue Underflow! Queue is empty.\n"); // Print error if empty
  } else {
    printf("\nDequeued element: %d\n",
           queue[front]); // Print the element being removed (at front)
    front++; // Increment front to remove the element logically (move to next)

    // Check if the queue has become empty after deletion
    if (front > rear) {
      front = -1; // Reset front to -1
      rear = -1;  // Reset rear to -1 to reinitialize the queue
    }
  }
}

// Function to display all elements in the queue
void display() {
  if (front == -1 || front > rear) { // Check if queue is empty
    printf("\nQueue is empty.\n");   // Print message if empty
  } else {
    printf("\nQueue elements: "); // Print label
    // Loop from the front index to the rear index
    for (int i = front; i <= rear; i++) {
      printf("%d ", queue[i]); // Print each element at index i
    }
    printf("\n"); // Print a newline at the end
  }
}

// Function to view the front element without removing it
void peek() {
  if (front == -1 || front > rear) { // Check if queue is empty
    printf("\nQueue is empty.\n");   // Print message if empty
  } else {
    printf("\nFront element: %d\n",
           queue[front]); // Print the element at the front index
  }
}
