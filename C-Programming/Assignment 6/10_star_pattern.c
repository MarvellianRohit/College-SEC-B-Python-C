/*
Question: Write a C program to print the following pattern (for N=5):
*
**
***
****
*****
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables for rows and columns
  int i, j, rows;

  // Prompt user for number of rows
  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  // Outer loop for rows
  for (i = 1; i <= rows; ++i) {
    // Inner loop for columns (printing stars)
    // For row 1, prints 1 star. For row 2, prints 2 stars, etc.
    for (j = 1; j <= i; ++j) {
      printf("*");
    }
    // Move to the next line after printing stars for the current row
    printf("\n");
  }

  // Return 0 for success
  return 0;
}
