/*
Question: Write a program to count the number of digits in a given number using
a while loop.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  // Use long long for number input to allow large numbers
  long long n;
  int count = 0;

  // Prompt user for input
  printf("Enter an integer: ");
  scanf("%lld", &n);

  // Handle case for 0 (0 has 1 digit)
  if (n == 0) {
    count = 1;
  } else {
    // Loop while n is not 0
    while (n != 0) {
      // Remove last digit
      n /= 10;
      // Increment counter
      ++count;
    }
  }

  // Print result
  printf("Number of digits: %d\n", count);

  // Return 0 for success
  return 0;
}
