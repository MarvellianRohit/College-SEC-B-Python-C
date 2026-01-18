/*
Question: Write a program to check if a number is positive using the ternary
operator ? :
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

  // Use ternary operator to check if num > 0
  // Syntax: (Condition) ? "True Code" : "False Code"
  (num > 0) ? printf("%d is positive.\n", num)
            : printf("%d is not positive.\n", num);

  // Return 0 for success
  return 0;
}
