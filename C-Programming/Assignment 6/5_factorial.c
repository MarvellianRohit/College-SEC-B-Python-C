/*
Question: Write a C program to calculate the factorial of a given number using a
for loop.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  // Use long long for factorial to handle larger numbers
  int num, i;
  long long factorial = 1;

  // Prompt user for number
  printf("Enter a number: ");
  scanf("%d", &num);

  // Check for negative input (factorial doesn't exist for negative numbers)
  if (num < 0) {
    printf("Error! Factorial of a negative number doesn't exist.\n");
  } else {
    // Loop from 1 to num to calculate factorial
    for (i = 1; i <= num; ++i) {
      // Multiply current value of factorial by i
      factorial = factorial * i;
    }
    // Print the result
    printf("Factorial of %d = %lld\n", num, factorial);
  }

  // Return 0 for success
  return 0;
}
