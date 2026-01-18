/*
Question: Write a C program to store and analyse the marks of students in a
class. The program should accept marks of N students (maximum 50). Provide a
menu-driven system using functions for the following tasks: i. Display all marks
ii. Find the average mark
iii. Find the highest and lowest marks
iv. Count how many students passed (marks >= 40)
*/

// Include standard input/output library
#include <stdio.h>

// Function to display all marks
// Takes array of marks and number of students as input
void displayMarks(int marks[], int n) {
  // Print header
  printf("\n--- All Marks ---\n");
  // Loop through each student
  for (int i = 0; i < n; i++) {
    // Print student index (1-based) and their mark
    printf("Student %d: %d\n", i + 1, marks[i]);
  }
}

// Function to find the average mark
void findAverage(int marks[], int n) {
  // Initialize sum to 0
  int sum = 0;
  // Loop through all marks
  for (int i = 0; i < n; i++) {
    // Add current mark to sum
    sum += marks[i];
  }
  // Calculate average by casting sum to float and dividing by n
  // Print the result formatted to 2 decimal places
  printf("\nAverage Mark: %.2f\n", (float)sum / n);
}

// Function to find highest and lowest marks
void findHighLow(int marks[], int n) {
  // Initialize max and min with the first mark
  int max = marks[0], min = marks[0];

  // Loop from the second mark to the end
  for (int i = 1; i < n; i++) {
    // If current mark is greater than max, update max
    if (marks[i] > max)
      max = marks[i];
    // If current mark is less than min, update min
    if (marks[i] < min)
      min = marks[i];
  }
  // Print the highest mark
  printf("\nHighest Mark: %d\n", max);
  // Print the lowest mark
  printf("Lowest Mark: %d\n", min);
}

// Function to count how many students passed
void countPass(int marks[], int n) {
  // Initialize counter
  int count = 0;
  // Loop through all marks
  for (int i = 0; i < n; i++) {
    // Check if mark is greater than or equal to 40
    if (marks[i] >= 40)
      count++;
  }
  // Print the total passed students
  printf("\nNumber of Students Passed: %d\n", count);
}

// Main function
int main() {
  // Declare marks array of size 50, number of students n, and menu choice
  int marks[50], n, choice;

  // Prompt user for number of students
  printf("Enter number of students (max 50): ");
  // Read n from user
  scanf("%d", &n);

  // Validate n (must be between 1 and 50)
  if (n > 50 || n < 1) {
    // Print error message
    printf("Invalid number of students.\n");
    // Exit with error code 1
    return 1;
  }

  // Prompt for marks input
  printf("Enter marks for %d students:\n", n);
  // Loop to read marks for n students
  for (int i = 0; i < n; i++) {
    // Prompt for specific student
    printf("Student %d: ", i + 1);
    // Read mark into array
    scanf("%d", &marks[i]);
  }

  // Do-while loop for menu
  do {
    // Display menu options
    printf("\n--- Menu ---\n");
    printf("1. Display all marks\n");
    printf("2. Find average mark\n");
    printf("3. Find highest and lowest marks\n");
    printf("4. Count students passed\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    // Read user choice
    scanf("%d", &choice);

    // Switch statement to handle choice
    switch (choice) {
    case 1:
      // Call display function
      displayMarks(marks, n);
      break;
    case 2:
      // Call average function
      findAverage(marks, n);
      break;
    case 3:
      // Call high/low function
      findHighLow(marks, n);
      break;
    case 4:
      // Call count pass function
      countPass(marks, n);
      break;
    case 5:
      // Exit message
      printf("Exiting...\n");
      break;
    default:
      // Handle invalid input
      printf("Invalid choice!\n");
    }
  } while (choice != 5); // Continue until choice is 5

  // Return 0 for success
  return 0;
}
