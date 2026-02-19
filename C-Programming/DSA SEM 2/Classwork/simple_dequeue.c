#include <stdio.h>
#include <stdlib.h>

// Define the size of our queue (like 5 seats in a row)
#define SIZE 5

int queue[SIZE]; // Our array to store numbers
int front = -1;  // Pointer to the first person in line
int rear = -1;   // Pointer to the last person in line

// Simple function to add a number (so we have something to delete)
void enqueue(int value) {
  if (rear == SIZE - 1) {
    printf("Queue is Full!\n");
  } else {
    if (front == -1)
      front = 0;
    rear++;
    queue[rear] = value;
    printf("Inserted %d\n", value);
  }
}

// THE DEQUEUE EXPLANATION FUNCTION
void dequeue() {
  // STEP 1: Check if the queue is empty
  // If front is -1, it means nobody is in the line!
  if (front == -1) {
    printf("\n--- UNDERFLOW! ---\n");
    printf("The queue is empty. There is nothing to delete.\n");
  } else {
    // STEP 2: Show which item we are deleting
    // We always delete from the 'front'
    printf("\n--- DELETING... ---\n");
    printf("Removing %d from the front of the queue.\n", queue[front]);

    // STEP 3: Simple logic for the pointers
    // If there was only ONE person left (front and rear are the same)
    if (front == rear) {
      // We set both back to -1, which means "The line is now empty"
      front = -1;
      rear = -1;
      printf("The queue is now completely empty.\n");
    } else {
      // Otherwise, we just move the 'front' pointer to the next person
      // It's like the first person left, so the second person is now the first!
      front++;
      printf("The front moved to the next position.\n");
    }
  }
}

// Function to show the current line using a simple for loop
void display() {
  if (front == -1) {
    printf("Queue is empty.\n");
  } else {
    printf("Current Queue: ");
    // We start from 'front' and go till 'rear'
    for (int i = front; i <= rear; i++) {
      printf("[%d] ", queue[i]);
    }
    printf("\n");
  }
}

int main() {
  // Let's add some data first
  printf("--- Preparing the Queue ---\n");
  enqueue(10);
  enqueue(20);
  enqueue(30);
  display();

  // Now let's demonstrate Dequeue
  printf("\n--- Dequeue Demonstration ---\n");
  dequeue(); // Deletes 10
  display();

  dequeue(); // Deletes 20
  display();

  return 0;
}
