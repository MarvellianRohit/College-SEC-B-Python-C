/*
Question: Write a program to print an inverted right triangle of stars.
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
  // Counts down from n to 1
  for (i = n; i >= 1; i--) {
    // Inner loop prints 'i' stars for current row
    for (j = 1; j <= i; j++) {
      printf("* ");
    }
    // Move to next line
    printf("\n");
  }

  // Return 0 for success
  return 0;
}
