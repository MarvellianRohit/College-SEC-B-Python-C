/*
Question: Write a C program to find the sum of all even and odd numbers up to N.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  int N, i, evenSum = 0, oddSum = 0;

  // Prompt user for N
  printf("Enter the value of N: ");
  scanf("%d", &N);

  // Loop from 1 to N
  for (i = 1; i <= N; i++) {
    // Check if number is even
    if (i % 2 == 0) {
      // Add to evenSum
      evenSum = evenSum + i;
    } else {
      // Add to oddSum
      oddSum = oddSum + i;
    }
  }

  // Print results
  printf("Sum of Even numbers up to %d = %d\n", N, evenSum);
  printf("Sum of Odd numbers up to %d = %d\n", N, oddSum);

  // Return 0 for success
  return 0;
}
