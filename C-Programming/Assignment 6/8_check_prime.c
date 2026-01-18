/*
Question: Write a C program to check whether a given number is prime or not
using a for loop.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  // flag is initialized to 0 (assuming number is prime initially)
  int n, i, flag = 0;

  // Prompt user for input
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  // 0 and 1 are not prime numbers
  if (n == 0 || n == 1) {
    flag = 1; // Mark as not prime
  }

  // Loop from 2 to n/2 to check for factors
  for (i = 2; i <= n / 2; ++i) {
    // If n is divisible by any number between 2 and n/2, it is not prime
    if (n % i == 0) {
      flag = 1; // Set flag to 1 indicating not prime
      break;    // Exit the loop
    }
  }

  // Check flag value
  if (flag == 0)
    printf("%d is a prime number.\n", n);
  else
    printf("%d is not a prime number.\n", n);

  // Return 0 for success
  return 0;
}
