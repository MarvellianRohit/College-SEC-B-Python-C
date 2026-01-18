/*
Question: Write a program to input a number and display whether it is positive,
negative, or zero using relational operators.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare integer variable
  int num;

  // Prompt user for input
  printf("Enter a number: ");
  scanf("%d", &num);

  // Check if number is greater than 0
  if (num > 0) {
    printf("%d is positive.\n", num);
  }
  // Check if number is less than 0
  else if (num < 0) {
    printf("%d is negative.\n", num);
  }
  // If neither, it must be zero
  else {
    printf("The number is zero.\n");
  }

  // Return 0 for success
  return 0;
}
