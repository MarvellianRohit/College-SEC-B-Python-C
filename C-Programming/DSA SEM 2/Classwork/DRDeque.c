#include <stdio.h>  // Standard I/O library (for printf and scanf)
#include <stdlib.h> // Standard library (for exit function)

#define SIZE 5 // Set the fixed capacity of our Deque buffer to 5

int deque[SIZE]; // The array that will hold our data
int front = -1;  // Pointer for the start of the line (initialized to empty)
int rear = -1;   // Pointer for the end of the line (initialized to empty)

// --- INSERTION (Allowed from the Rear end) ---
void insert_rear(int value) {
  // Check if the Deque is already full using circular math
  if ((rear + 1) % SIZE == front) {
    printf("Overflow! Cannot insert %d at the rear.\n", value);
  } else {
    // If we are adding the very first element
    if (front == -1) {
      front = 0; // Set front to start of array
    }
    // Move rear forward circularly (wraps back to 0 if it goes past index 4)
    rear = (rear + 1) % SIZE;

    // Save the value at the new rear position
    deque[rear] = value;

    // Tell the user it worked
    printf("Inserted %d at the Rear.\n", value);
  }
}

// --- INSERTION (Allowed from the Front end) ---
void insert_front(int value) {
  // Check if Deque is full:
  // Case A: Front is 0 and Rear is 4. Case B: Front is right after Rear.
  if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
    printf("Overflow! Cannot insert %d at the front.\n", value);
  } else {
    // If the Deque is currently empty
    if (front == -1) {
      front = 0; // Initialize both to index 0
      rear = 0;
    }
    // If front is at index 0, wrapping back to index 4 (circular movement)
    else if (front == 0) {
      front = SIZE - 1;
    }
    // Otherwise, move front back by one index
    else {
      front--;
    }
    // Place the value in the new front slot
    deque[front] = value;

    // Confirm the action
    printf("Inserted %d at the Front.\n", value);
  }
}

// --- DELETION (Only allowed from the Front end) ---
void delete_front() {
  // Check for Underflow (if Deque is empty)
  if (front == -1) {
    printf("Underflow! Nothing to remove from the front.\n");
  } else {
    // Show which value is being popped out
    printf("Deleted %d from the Front.\n", deque[front]);

    // Special case: if there was only one item left
    if (front == rear) {
      // Reset to empty state
      front = -1;
      rear = -1;
    } else {
      // Move front forward circularly
      front = (front + 1) % SIZE;
    }
  }
}

// --- DISPLAY (Looping through and showing elements) ---
void display() {
  if (front == -1) {
    printf("The Deque is empty.\n");
  } else {
    printf("Deque State: ");
    int i = front; // Start a temporary index 'i' at 'front'

    // Use an infinite while loop and break when we hit 'rear'
    while (1) {
      printf("%d ", deque[i]); // Print the element

      // If we've reached the last element (rear), stop the loop
      if (i == rear)
        break;

      // Move 'i' to next index circularly
      i = (i + 1) % SIZE;
    }
    printf("\n"); // Format with a new line
  }
}

// --- MAIN (User interface for the program) ---
int main() {
  int choice, val; // Helper variables for input

  // Main loop for the menu
  while (1) {
    printf("\n--- Deletion Restricted Deque Menu ---\n");
    printf("1. Insert at Rear\n");
    printf("2. Insert at Front\n");
    printf("3. Delete from Front (Only Exit Point)\n");
    printf("4. Display Deque\n");
    printf("5. Exit\n");
    printf("Enter choice (1-5): ");
    scanf("%d", &choice); // Capture user's menu selection

    // Branching based on choice
    switch (choice) {
    case 1:
      printf("Value to insert at Rear: ");
      scanf("%d", &val);
      insert_rear(val); // Run Rear-Insertion
      break;
    case 2:
      printf("Value to insert at Front: ");
      scanf("%d", &val);
      insert_front(val); // Run Front-Insertion
      break;
    case 3:
      delete_front(); // Run Front-Deletion (ONLY choice for exit)
      break;
    case 4:
      display(); // View current Deque
      break;
    case 5:
      printf("Closing Program... Done.\n");
      exit(0); // End program
    default:
      printf("Invalid! Please pick between 1 and 5.\n");
    }
  }
  return 0; // Return zero for standard program exit
}
