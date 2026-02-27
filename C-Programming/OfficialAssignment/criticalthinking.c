#include <stdio.h> // Including standard input-output library for printf and scanf
#include <stdlib.h> // Including standard library for general functions

/**
 * PROJECT: Library Book Issuing System
 * STUDENT: Rohit (BCA 1st Year)
 */

// --- GLOBAL VARIABLES (Accessible from anywhere in the program) ---

int bookStack[20]; // An array to store up to 20 Book IDs (The Stack)
int top = -1; // 'top' tracks the last book added. -1 means the stack is empty.

int studentQueue[20]; // An array to store up to 20 Student IDs (The Queue)
int front = 0;        // 'front' marks the first student in line
int rear = -1;        // 'rear' marks the last student in line

// --- STACK FUNCTIONS (LIFO: Last-In, First-Out) ---

// Function to add (push) a book onto the stack
void pushBook(int bookId) {
  if (top < 19) {  // Check if there is space (max 20 books, index 0-19)
    top = top + 1; // Move the top pointer up by 1
    bookStack[top] = bookId; // Place the book ID at the new top position
    printf("Book %d added to stack.\n", bookId); // Print confirmation
  }
}

// Function to remove (pop) a book from the stack top
int popBook() {
  if (top >= 0) {                // Check if the stack is not empty
    int bookId = bookStack[top]; // Get the book ID from the current top
    top = top - 1;               // Move the top pointer down by 1
    return bookId;               // Return the book ID that was removed
  }
  return -1; // Return -1 if the stack was empty
}

// --- QUEUE FUNCTIONS (FIFO: First-In, First-Out) ---

// Function to add (enqueue) a student to the back of the line
void enqueueStudent(int studentId) {
  if (rear < 19) {                  // Check if there is space in the queue
    rear = rear + 1;                // Move the rear pointer forward
    studentQueue[rear] = studentId; // Place the student ID at the new rear
    printf("Student %d added to queue.\n", studentId); // Print confirmation
  }
}

// Function to remove (dequeue) a student from the front of the line
int dequeueStudent() {
  if (front <= rear) {                   // Check if the queue is not empty
    int studentId = studentQueue[front]; // Get the student from the front
    front = front + 1; // Move the front pointer forward to the next student
    return studentId;  // Return the student ID that was removed
  }
  return -1; // Return -1 if the queue was empty
}

// --- MAIN PROGRAM EXECUTION ---
int main() {
  long int rollNumber; // Variable to store the user's roll number
  int R, S, B, W;      // Variables for the required math parameters

  // Print the welcome header
  printf("========================================\n");
  printf("      ROHIT'S LIBRARY SYSTEM (BCA)     \n");
  printf("========================================\n");

  // Ask user for their roll number
  printf("\nWelcome, Rohit!\nPlease enter your roll number: ");
  scanf("%ld", &rollNumber); // Read the roll number from the keyboard

  // --- Personalization Rule (Calculating Values) ---

  // R = The last digit of the roll number (using modulo 10)
  R = rollNumber % 10;

  // S = The sum of all digits in the roll number
  S = 0;                      // Start the sum at 0
  long int temp = rollNumber; // Copy roll number to a temporary variable
  if (temp < 0)
    temp = -temp;        // Make it positive if it's negative
  while (temp > 0) {     // Loop until all digits are processed
    S = S + (temp % 10); // Add the last digit to the sum
    temp = temp / 10;    // Remove the last digit from the number
  }

  // B (Books) = Calculation based on R
  B = (R % 5) + 5;

  // W (Students) = Calculation based on S
  W = (S % 6) + 4;

  // Show calculated metrics
  printf("\n>>> Your Details:\n");
  printf("B (Books to return): %d\n", B);
  printf("W (Waiting students): %d\n", W);

  // Step 1: Add a specific number of books (B) to the stack
  printf("\n--- Step 1: Adding Books ---\n");
  for (int i = 0; i < B; i++) {
    pushBook(5001 + i); // Books start from ID 5001
  }

  // Step 2: Add a specific number of students (W) to the queue
  printf("\n--- Step 2: Adding Students ---\n");
  for (int i = 0; i < W; i++) {
    enqueueStudent(101 + i); // Students start from ID 101
  }

  // Step 3: Issue books until either books or students run out
  printf("\n--- Step 3: Issuing Process ---\n");
  while (top != -1 &&
         front <= rear) { // While stack is not empty AND queue is not empty
    int book = popBook(); // Take book from top (LIFO)
    int student = dequeueStudent(); // Take student from front (FIFO)
    printf("Book %d given to Student %d\n", book, student); // Display issuance
  }

  // Step 4: Show the final results
  printf("\n--- Step 4: Final Status ---\n");
  if (top == -1) { // If the top pointer is back at -1
    printf("All books are issued!\n");
  } else {
    printf("Books remaining in stack.\n");
  }

  if (front > rear) { // If the front has passed the rear
    printf("All students got their books!\n");
  } else {
    printf("Some students are still waiting.\n");
  }

  printf("\n========================================\n");
  return 0; // Tell the OS the program finished successfully
}