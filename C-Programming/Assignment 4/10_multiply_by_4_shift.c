/*
Question: Write a program to multiply a number by 4 using the left shift (<<)
operator.
// Multiply by 4 using left shift (2 bits).
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare integer variable
  int num, result;

  // Prompt user for input
  printf("Enter an integer: ");
  scanf("%d", &num);

  // Left shift by 2 positions is equivalent to multiplying by 2^2 i.e., 4
  // Formula: num << n = num * 2^n
  result = num << 2;

  // Print result
  printf("%d multiplied by 4 is %d\n", num, result);

  // Return 0 for success
  return 0;
}
