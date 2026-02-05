#include <stdio.h>  // Include standard input-output library
#include <stdlib.h> // Include standard library for exit()

#define MAX 10 // Define a constant MAX with value 10 for queue size

int queue[MAX]; // Declare an array 'queue' of size MAX
int front = -1; // Initialize front to -1 (empty state)
int rear = -1;  // Initialize rear to -1 (empty state)

// Function prototypes
void enqueue(int data);
void dequeue();
void display();
void peek();

int main() {
  int choice, value; // Variables for user input

  // Infinite loop for menu
  while (1) {
    printf("\n*** Circular Queue Menu ***\n"); // Menu Header
    printf("1. Enqueue\n");                    // Option 1
    printf("2. Dequeue\n");                    // Option 2
    printf("3. Display\n");                    // Option 3
    printf("4. Peek\n");                       // Option 4
    printf("5. Exit\n");                       // Option 5
    printf("Enter your choice: ");             // Prompt for choice
    scanf("%d", &choice);                      // Read choice

    switch (choice) {
    case 1:
      printf("Enter value to enqueue: "); // Prompt for value
      scanf("%d", &value);                // Read value
      enqueue(value);                     // Call enqueue
      break;
    case 2:
      dequeue(); // Call dequeue
      break;
    case 3:
      display(); // Call display
      break;
    case 4:
      peek(); // Call peek
      break;
    case 5:
      printf("Exiting...\n"); // Exit message
      exit(0);                // Terminate program
    default:
      printf("Invalid choice! Please try again.\n"); // Error message
    }
  }
  return 0;
}

// Function to add element to circular queue
void enqueue(int data) {
  // Check if the next position of rear is front (Circular Overflow condition)
  if ((rear + 1) % MAX == front) {
    printf("\nQueue Overflow! Cannot enqueue %d.\n", data); // Queue is full
  } else {
    if (front == -1) { // Check if queue is initially empty
      front = 0;       // Set front to 0
      rear = 0;        // Set rear to 0
    } else {
      // Circular increment: rear moves to next position, wrapping around if
      // needed
      rear = (rear + 1) % MAX;
    }
    queue[rear] = data; // insert data at the new rear position
    printf("\nEnqueued %d into circular queue.\n", data); // Confirm insertion
  }
}

// Function to remove element from circular queue
void dequeue() {
  if (front == -1) { // Check if queue is empty (Underflow)
    printf("\nQueue Underflow! Queue is empty.\n"); // Error if empty
  } else {
    printf("\nDequeued element: %d\n",
           queue[front]); // meaningful print of removed element
    if (front == rear) {  // Check if there was only one element left
      // Reset both to -1 to mark queue as empty
      front = -1;
      rear = -1;
    } else {
      // Circular increment: front moves to next position, wrapping around
      front = (front + 1) % MAX;
    }
  }
}

// Function to display elements
void display() {
  if (front == -1) { // Check if queue is empty
    printf("\nQueue is empty.\n");
  } else {
    printf("\nQueue elements: ");
    int i = front; // Start from front

    // Loop until i reaches rear. Use while because rear can be smaller than
    // front (wrap around)
    while (i != rear) {
      printf("%d ", queue[i]); // Print current element
      i = (i + 1) % MAX;       // Move to next position circularly
    }
    printf("%d ", queue[rear]); // Print the last element (at rear) which wasn't
                                // printed in loop
    printf("\n");
  }
}

// Function to see front element
void peek() {
  if (front == -1) { // Check if empty
    printf("\nQueue is empty.\n");
  } else {
    printf("\nFront element: %d\n", queue[front]); // Print element at front
  }
}
