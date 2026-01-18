/*
Question: Write a C program to print a square pattern of * with size n.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  int n, i, j;

  // Prompt for size
  printf("Enter the size of the square: ");
  scanf("%d", &n);

  // Outer loop for rows
  for (i = 1; i <= n; i++) {
    // Inner loop for columns
    for (j = 1; j <= n; j++) {
      // Print star followed by space
      printf("* ");
    }
    // Move to next line after each row
    printf("\n");
  }

  // Return 0 for success
  return 0;
}
