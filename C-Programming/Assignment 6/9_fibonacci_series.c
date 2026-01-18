/*
Question: Write a C program to print the first N terms of the Fibonacci series
using a for loop.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  int n, first = 0, second = 1, next, i;

  // Prompt user for number of terms
  printf("Enter the number of terms: ");
  scanf("%d", &n);

  printf("Fibonacci Series: ");

  // Loop to generate n terms
  for (i = 1; i <= n; ++i) {
    // Print the first term
    printf("%d ", first);

    // Calculate the next term
    next = first + second;

    // Update first and second variables for the next iteration
    first = second;
    second = next;
  }
  printf("\n");

  // Return 0 for success
  return 0;
}
