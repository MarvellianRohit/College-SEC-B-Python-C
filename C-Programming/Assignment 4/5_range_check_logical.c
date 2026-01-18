/*
Question: Write a program that takes an integer and checks if it lies between 10
and 100 using logical operators.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variable
  int num;

  // Prompt user for input
  printf("Enter an integer: ");
  scanf("%d", &num);

  // Check if number is greater than 10 AND less than 100
  // Using logical AND operator (&&)
  if (num > 10 && num < 100) {
    printf("%d is between 10 and 100.\n", num);
  } else {
    printf("%d is NOT between 10 and 100.\n", num);
  }

  // Return 0 for success
  return 0;
}
