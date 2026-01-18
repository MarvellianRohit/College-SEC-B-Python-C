/*
Question: Write a program to find the HCF of two numbers using a while loop.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables for two numbers and HCF
  int n1, n2;

  // Prompt user for input
  printf("Enter two positive integers: ");
  scanf("%d %d", &n1, &n2);

  // Euclidean algorithm using subtraction
  // Loop until n1 equals n2
  while (n1 != n2) {
    // If n1 is greater, subtract n2 from n1
    if (n1 > n2)
      n1 -= n2;
    else
      // If n2 is greater, subtract n1 from n2
      n2 -= n1;
  }

  // When n1 equals n2, that is the HCF
  printf("HCF/GCD = %d\n", n1);

  // Return 0 for success
  return 0;
}
