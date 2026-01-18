/*
Question: Write a program to print a half pyramid using alphabets.
Pattern:
A
A B
A B C
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
    // 'A' + j - 1 calculates the character to print
    for (j = 0; j < i; j++) {
      // %c prints character
      printf("%c ", 'A' + j);
    }
    // Move to next line
    printf("\n");
  }

  // Return 0 for success
  return 0;
}
