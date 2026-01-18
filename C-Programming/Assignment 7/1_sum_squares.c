/*
Question: Write a program to calculate the sum of squares of the first N natural
numbers using a for loop.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  // N is the limit, i is the loop counter, sum stores the total
  int N, i, sum = 0;

  // Prompt user for input
  printf("Enter the value of N: ");
  scanf("%d", &N);

  // Loop from 1 to N
  for (i = 1; i <= N; i++) {
    // Add square of i to sum
    // i * i calculates the square
    sum = sum + (i * i);
  }

  // Print the result
  printf("Sum of squares of first %d natural numbers is: %d\n", N, sum);

  // Return 0 for success
  return 0;
}
