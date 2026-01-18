/*
Question: Write a C program to print the first N natural numbers using a for
loop.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  int N, i;

  // Prompt user for N
  printf("Enter the value of N: ");
  scanf("%d", &N);

  // Print header
  printf("First %d natural numbers are:\n", N);

  // For loop starting from 1 up to N
  for (i = 1; i <= N; i++) {
    // Print the current number followed by a space
    printf("%d ", i);
  }
  // Print a newline at the end
  printf("\n");

  // Return 0 for success
  return 0;
}
