/*
Question: Write a C program to print a half pyramid of repeated alphabets.
Pattern:
A
B B
C C C
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
    for (j = 1; j <= i; j++) {
      // Print character corresponding to row number i
      // 'A' + i - 1 gives 'A' for i=1, 'B' for i=2, etc.
      printf("%c ", 'A' + i - 1);
    }
    // Move to next line
    printf("\n");
  }

  // Return 0 for success
  return 0;
}
