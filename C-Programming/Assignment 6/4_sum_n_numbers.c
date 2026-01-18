/*
Question: Write a C program to find the sum of the first N natural numbers using
a for loop.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  int N, i, sum = 0;

  // Prompt user for N
  printf("Enter the value of N: ");
  scanf("%d", &N);

  // Loop from 1 to N to calculate sum
  for (i = 1; i <= N; i++) {
    // Add current number 'i' to 'sum'
    sum = sum + i;
  }

  // Print the final sum
  printf("Sum of first %d natural numbers is: %d\n", N, sum);

  // Return 0 for success
  return 0;
}
