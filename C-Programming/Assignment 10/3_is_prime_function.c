/*
Question: Write a function to check whether a number is a prime number.
*/

// Include standard input/output library
#include <stdio.h>

// Function to check prime
// Returns 1 if prime, 0 otherwise
int isPrime(int n) {
  // 0 and 1 are not prime
  if (n <= 1)
    return 0;

  // Check for factors from 2 to n/2
  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
      // Found a factor, so not prime
      return 0;
    }
  }
  // No factors found, is prime
  return 1;
}

// Main function
int main() {
  // Declare variable
  int n;

  // Prompt user for input
  printf("Enter a number: ");
  scanf("%d", &n);

  // Call function
  if (isPrime(n)) {
    printf("%d is a prime number.\n", n);
  } else {
    printf("%d is not a prime number.\n", n);
  }

  // Return 0 for success
  return 0;
}
