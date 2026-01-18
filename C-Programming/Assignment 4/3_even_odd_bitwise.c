/*
Question: Write a program to check if a number is even or odd using bitwise
operator.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variable
  int num;

  // Prompt user for input
  printf("Enter an integer: ");
  // Read input
  scanf("%d", &num);

  // Check the least significant bit
  // If (num & 1) is true (1), the number is odd
  if (num & 1) {
    printf("%d is odd.\n", num);
  } else {
    // If (num & 1) is false (0), the number is even
    printf("%d is even.\n", num);
  }

  // Return 0 for success
  return 0;
}
