/*
Question: Write a function to reverse a number using iteration.
*/

// Include standard input/output library
#include <stdio.h>

// Function to reverse a number
int reverseNumber(int n) {
  int reversed = 0, remainder;
  // Iterate until n becomes 0
  while (n != 0) {
    // Get last digit
    remainder = n % 10;
    // Append digit to reversed number
    reversed = reversed * 10 + remainder;
    // Remove last digit from n
    n /= 10;
  }
  return reversed;
}

// Main function
int main() {
  // Declare variable
  int n;

  // Prompt user for input
  printf("Enter an integer: ");
  scanf("%d", &n);

  // Call function and print result
  printf("Reversed Number: %d\n", reverseNumber(n));

  // Return 0 for success
  return 0;
}
