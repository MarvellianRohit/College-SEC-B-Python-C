/*
Question: Write a function that takes two integers as input and returns their
greatest common divisor (GCD).
*/

// Include standard input/output library
#include <stdio.h>

// Function to calculate GCD
int gcd(int n1, int n2) {
  // If n2 is 0, GCD is n1
  if (n2 == 0)
    return n1;
  // Recursive call: gcd(n2, n1 % n2)
  return gcd(n2, n1 % n2);
}

// Main function
int main() {
  // Declare variables
  int n1, n2;

  // Prompt user for input
  printf("Enter two positive integers: ");
  scanf("%d %d", &n1, &n2);

  // Call gcd function and print result
  printf("GCD of %d and %d is %d\n", n1, n2, gcd(n1, n2));

  // Return 0 for success
  return 0;
}
