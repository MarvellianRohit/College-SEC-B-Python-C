/*
Question: Write a program to check whether a number is a palindrome using a
while loop.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  int n, reversed = 0, remainder, original;

  // Prompt user for input
  printf("Enter an integer: ");
  scanf("%d", &n);

  // Save original number to compare later
  original = n;

  // Reverse the number
  while (n != 0) {
    // Extract last digit
    remainder = n % 10;

    // Build reversed number
    reversed = reversed * 10 + remainder;

    // Remove last digit
    n /= 10;
  }

  // Check if original is equal to reversed
  if (original == reversed)
    printf("%d is a palindrome.\n", original);
  else
    printf("%d is not a palindrome.\n", original);

  // Return 0 for success
  return 0;
}
