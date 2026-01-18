/*
Question: Write a C program to print a triangle of numbers from 1 to n.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  int n, i, j;

  // Prompt for number of rows
  printf("Enter the number of rows: ");
  scanf("%d", &n);

  // Outer loop for rows
  for (i = 1; i <= n; i++) {
    // Inner loop for columns
    // Prints numbers from 1 to i
    for (j = 1; j <= i; j++) {
      printf("%d ", j);
    }
    // Move to next line
    printf("\n");
  }

  // Return 0 for success
  return 0;
}
