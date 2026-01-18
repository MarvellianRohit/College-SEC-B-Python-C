/*
Question: Write a C program to print a Floyd’s Triangle.
Pattern:
1
2 3
4 5 6
7 8 9 10
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  // num keeps track of the current number to print
  int n, i, j, num = 1;

  // Prompt for number of rows
  printf("Enter the number of rows: ");
  scanf("%d", &n);

  // Outer loop for rows
  for (i = 1; i <= n; i++) {
    // Inner loop for columns
    for (j = 1; j <= i; j++) {
      // Print current number
      printf("%d ", num);
      // Increment number for next position
      num++;
    }
    // Move to next line
    printf("\n");
  }

  // Return 0 for success
  return 0;
}
