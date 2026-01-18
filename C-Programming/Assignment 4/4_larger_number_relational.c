/*
Question: Write a program to compare two integers and print the larger number
using relational operators.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare two integer variables
  int num1, num2;

  // Prompt user for first number
  printf("Enter first integer: ");
  scanf("%d", &num1);

  // Prompt user for second number
  printf("Enter second integer: ");
  scanf("%d", &num2);

  // Compare numbers using relational operator >
  if (num1 > num2) {
    // If num1 is greater
    printf("%d is larger.\n", num1);
  } else if (num2 > num1) {
    // If num2 is greater
    printf("%d is larger.\n", num2);
  } else {
    // If both are equal
    printf("Both numbers are equal.\n");
  }

  // Return 0 for success
  return 0;
}
