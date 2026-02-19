#include <stdio.h> // Include standard input-output library for basic input/output operations
#include <stdlib.h> // Include standard library for functions like exit()

#define SIZE 5 // Define the fixed maximum size of the circular queue

int queue[SIZE]; // Global array to represent the circular queue buffer
int front = -1;  // Initialize front pointer to -1, indicating an empty queue
int rear = -1;   // Initialize rear pointer to -1, indicating an empty queue

// Function to insert an element into the queue (Insertion Queue)
void enqueue(int value) {
  // Check for OVERFLOW: Queue is full if (rear + 1) % SIZE matches front
  if ((rear + 1) % SIZE == front) {
    printf("Queue Overflow! Cannot insert %d because the queue is full.\n",
           value); // Error message for overflow
  } else {
    // If the queue is empty (front is -1), initialize front to 0 for the first
    // element
    if (front == -1) {
      front = 0; // Set front to 0 to point to the first element
    }

    // Calculate the next rear position circularly using the modulo operator
    rear = (rear + 1) %
           SIZE; // This wraps the index back to 0 if it exceeds (SIZE - 1)

    // Store the input value at the newly calculated rear position in the array
    queue[rear] = value;

    // Print a confirmation message showing the successfully inserted value
    printf("Inserted %d successfully into the queue.\n", value);
  }
}

// Function to delete an element from the queue (Deletion Queue)
void dequeue() {
  // Check for UNDERFLOW: Queue is empty if front is -1
  if (front == -1) {
    printf(
        "Queue Underflow! Cannot delete because the queue is empty.\n"); // Error
                                                                         // message
                                                                         // for
                                                                         // underflow
  } else {
    // Print the element currently at the front which is about to be 'deleted'
    printf("Deleted %d from the queue.\n", queue[front]);

    // If there was only one element left in the queue (front equals rear)
    if (front == rear) {
      // Reset both pointers to -1 to signify the queue is now completely empty
      front = -1;
      rear = -1;
    } else {
      // Otherwise, move the front pointer to the next position circularly using
      // modulo
      front = (front + 1) %
              SIZE; // Keeps the index within the bounds of [0, SIZE-1]
    }
  }
}

// Function to display all current elements in the circular queue
void display() {
  // Check for Underflow (Empty Queue) before attempting to traverse
  if (front == -1) {
    printf("Queue is currently empty (Underflow situation).\n");
  } else {
    printf("Current Queue Elements: ");

    if (front <= rear) {
      // Case 1: Elements are in a single linear block (Front is before or at
      // Rear)
      for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
      }
    } else {
      // Case 2: Elements are wrapped around the end of the array (Front is
      // after Rear) First loop: from the 'front' pointer to the literal end of
      // the array
      for (int i = front; i < SIZE; i++) {
        printf("%d ", queue[i]);
      }
      // Second loop: from the start of the array back to the 'rear' pointer
      for (int i = 0; i <= rear; i++) {
        printf("%d ", queue[i]);
      }
    }
    printf("\n");
  }
}

// Main function to drive the menu-based interface
int main() {
  int choice, value; // Variables to store the user's menu choice and numeric
                     // input values

  // Continuous loop to keep providing the menu until the user chooses to exit
  while (1) {
    // Display available operations to the user
    printf("\n--- Circular Queue Operations ---\n");
    printf("1. Enqueue (Insertion)\n");
    printf("2. Dequeue (Deletion)\n");
    printf("3. Display Queue\n");
    printf("4. Exit Program\n");

    // Ask the user to input their choice
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice); // Reading choice from standard input

    // Switch case to execute the function corresponding to the user's choice
    switch (choice) {
    case 1:
      // Case for Insertion: Get value from user and call enqueue
      printf("Enter the integer value to be inserted: ");
      scanf("%d", &value); // Reading value to insert
      enqueue(value);      // Execute insertion
      break;
    case 2:
      // Case for Deletion: Simply call the dequeue function
      dequeue(); // Execute deletion
      break;
    case 3:
      // Case for Display: Call display to view current contents
      display(); // Execute display
      break;
    case 4:
      // Case for Exit: Print leaving message and terminate
      printf("Exiting the program. Goodbye!\n");
      exit(0); // Exit with success status
    default:
      // Handling any input that isn't 1-4
      printf("Invalid selection! Please choose a valid option from 1 to 4.\n");
    }
  }

  return 0; // Return 0 as standard practice for successful program completion
}
