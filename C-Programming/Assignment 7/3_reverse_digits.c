/*
Question: Write a program to reverse the digits of a given number using a for
loop.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  int n, reverse = 0, remainder;

  // Prompt user for input
  printf("Enter an integer: ");
  scanf("%d", &n);

  // We use a for loop structure: for(; condition; increment/decrement)
  // Initialization is empty because n is already set.
  // Condition check: n != 0
  // After each iteration: n = n / 10

  for (; n != 0; n /= 10) {
    // Get the last digit
    remainder = n % 10;

    // Append digit to reverse
    reverse = reverse * 10 + remainder;
  }

  // Print reversed number
  printf("Reversed Number = %d\n", reverse);

  // Return 0 for success
  return 0;
}
