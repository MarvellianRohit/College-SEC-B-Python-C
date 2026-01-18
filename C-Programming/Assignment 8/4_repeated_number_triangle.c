/*
Question: Write a program to print a triangle of repeated numbers.
Pattern:
1
2 2
3 3 3
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  int n, i, j;

  // Prompt for input
  printf("Enter the number of rows: ");
  scanf("%d", &n);

  // Outer loop for rows
  for (i = 1; i <= n; i++) {
    // Inner loop for columns
    for (j = 1; j <= i; j++) {
      // Print the current row number 'i'
      printf("%d ", i);
    }
    // Move to next line
    printf("\n");
  }

  // Return 0 for success
  return 0;
}
