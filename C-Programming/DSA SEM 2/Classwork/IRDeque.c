#include <stdio.h>  // Include library for input/output (printf, scanf)
#include <stdlib.h> // Include library for general functions (exit)

#define SIZE 5 // Define a constant 'SIZE' as 5 for our array capacity

int deque[SIZE]; // Declare an integer array of size 5 to act as our Deque
int front = -1;  // Initialize 'front' pointer to -1 (means Deque is empty)
int rear = -1;   // Initialize 'rear' pointer to -1 (means Deque is empty)

// --- INSERTION (Only allowed from the Rear end) ---
void insert_rear(int value) {
  // Check if the Deque is already full using circular logic
  // If (rear + 1) % 5 equals front, it means we have no empty slots left
  if ((rear + 1) % SIZE == front) {
    printf("Deque Overflow! No space to insert %d.\n", value);
  } else {
    // If this is the very first item being added to the Deque
    if (front == -1) {
      front = 0; // Set front to 0 because we now have our first element
    }
    // Move the rear index to the next position circularly
    // Example: if rear was 4, (4+1)%5 becomes 0 (wraps back to start)
    rear = (rear + 1) % SIZE;

    // Put the user's value into the array at the new rear position
    deque[rear] = value;

    // Confirm the insertion to the user
    printf("Inserted %d at the Rear.\n", value);
  }
}

// --- DELETION (Allowed from the Front end) ---
void delete_front() {
  // Check if the Deque is empty (front will be -1)
  if (front == -1) {
    printf("Deque Underflow! Nothing to delete from front.\n");
  } else {
    // Tell the user which value is being removed from index 'front'
    printf("Deleted %d from the Front.\n", deque[front]);

    // If there was ONLY ONE item in the Deque (front matches rear)
    if (front == rear) {
      // Reset both to -1 because the Deque is now completely empty
      front = -1;
      rear = -1;
    } else {
      // Otherwise, move the front pointer forward circularly
      // (front + 1) % 5 ensures we wrap around if we go past the end
      front = (front + 1) % SIZE;
    }
  }
}

// --- DELETION (Allowed from the Rear end) ---
void delete_rear() {
  // Check if the Deque is already empty
  if (front == -1) {
    printf("Deque Underflow! Nothing to delete from rear.\n");
  } else {
    // Tell the user which value is being removed from index 'rear'
    printf("Deleted %d from the Rear.\n", deque[rear]);

    // If there was only one item (front and rear point to the same slot)
    if (front == rear) {
      // Reset to empty state
      front = -1;
      rear = -1;
    }
    // If rear is currently at the very start (index 0)
    else if (rear == 0) {
      // Wrap rear back to the very end of the array (index 4)
      rear = SIZE - 1;
    } else {
      // Simply move the rear index back by one
      rear--;
    }
  }
}

// --- DISPLAY (Show all items currently in the Deque) ---
void display() {
  // If front is -1, there's nothing to show
  if (front == -1) {
    printf("Deque is empty.\n");
  } else {
    printf("Current Deque Items: ");
    int i = front; // Start a temporary counter 'i' at the 'front'

    // Loop until we reach the 'rear' index
    while (1) {
      printf("%d ", deque[i]); // Print the item at current index 'i'

      // If the current index 'i' has reached 'rear', we stop
      if (i == rear)
        break;

      // Move 'i' forward circularly (wrap back to 0 if needed)
      i = (i + 1) % SIZE;
    }
    printf("\n"); // Print a new line at the end
  }
}

// --- MAIN (The entry point and menu system) ---
int main() {
  int choice, val; // Variables to store user input

  // An infinite loop to keep showing the menu until 'Exit' is chosen
  while (1) {
    printf("\n--- Insertion Restricted Deque Menu ---\n");
    printf("1. Insert Item at Rear (Only Entry Point)\n");
    printf("2. Delete Item from Front\n");
    printf("3. Delete Item from Rear\n");
    printf("4. Display All Items\n");
    printf("5. Exit Program\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice); // Read the menu number from user

    // Use a switch to run the correct function based on 'choice'
    switch (choice) {
    case 1:
      printf("Enter the integer value to add: ");
      scanf("%d", &val); // Read the number to insert
      insert_rear(val);  // Call the insertion function
      break;
    case 2:
      delete_front(); // Call front-deletion function
      break;
    case 3:
      delete_rear(); // Call rear-deletion function
      break;
    case 4:
      display(); // Show the current Deque state
      break;
    case 5:
      printf("Exiting... Goodbye!\n");
      exit(0); // Stop the program
    default:
      printf("Invalid selection! Please choose 1-5.\n");
    }
  }
  return 0; // Return success status
}
