/*
Question: Write a program to calculate the sum of digits of a number using a
while loop.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  int n, sum = 0, remainder;

  // Prompt user for input
  printf("Enter an integer: ");
  scanf("%d", &n);

  // While loop runs as long as n is not 0
  while (n != 0) {
    // Get the last digit
    remainder = n % 10;

    // Add digit to sum
    sum = sum + remainder;

    // Remove the last digit
    n = n / 10;
  }

  // Print the sum
  printf("Sum of digits = %d\n", sum);

  // Return 0 for success
  return 0;
}
