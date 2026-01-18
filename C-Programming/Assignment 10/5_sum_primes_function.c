/*
Question: Write a function that accepts a number and returns the sum of all
prime numbers up to that number.
*/

// Include standard input/output library
#include <stdio.h>

// Helper function to check prime (reused logic)
int isPrime(int n) {
  if (n <= 1)
    return 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

// Function to calculate sum of primes up to n
int sumOfPrimes(int n) {
  int sum = 0;
  // Iterate from 2 to n
  for (int i = 2; i <= n; i++) {
    // If i is prime, add to sum
    if (isPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

// Main function
int main() {
  // Declare variable
  int n;

  // Prompt user for input
  printf("Enter a number: ");
  scanf("%d", &n);

  // Call function and print result
  printf("Sum of prime numbers up to %d is: %d\n", n, sumOfPrimes(n));

  // Return 0 for success
  return 0;
}
