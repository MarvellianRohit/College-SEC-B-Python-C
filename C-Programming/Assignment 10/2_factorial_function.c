/*
Question: Write a function to find the factorial of a number.
*/

// Include standard input/output library
#include <stdio.h>

// Function to calculate factorial
// Using long long for larger results
long long factorial(int n) {
  long long fact = 1;
  // Loop from 1 to n
  for (int i = 1; i <= n; i++) {
    fact = fact * i;
  }
  return fact;
}

// Main function
int main() {
  // Declare variable
  int n;

  // Prompt user for input
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  // Check for negative input
  if (n < 0) {
    printf("Error! Factorial of a negative number doesn't exist.\n");
  } else {
    // Call function and print result
    printf("Factorial of %d = %lld\n", n, factorial(n));
  }

  // Return 0 for success
  return 0;
}
