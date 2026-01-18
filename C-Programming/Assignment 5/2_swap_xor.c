/*
Question: Write a program to input two numbers and swap them using bitwise XOR
(^) operator.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare two integer variables
  int a, b;

  // Prompt user for inputs
  printf("Enter value for a: ");
  scanf("%d", &a);
  printf("Enter value for b: ");
  scanf("%d", &b);

  // Display values before swapping
  printf("\nBefore Swapping: a = %d, b = %d\n", a, b);

  // Swapping logic using XOR (^)
  // Step 1: a becomes bitwise XOR of a and b
  a = a ^ b;
  // Step 2: b becomes bitwise XOR of new a and b (which results in original a)
  b = a ^ b;
  // Step 3: a becomes bitwise XOR of new a and new b (which results in original
  // b)
  a = a ^ b;

  // Display values after swapping
  printf("After Swapping:  a = %d, b = %d\n", a, b);

  // Return 0 for success
  return 0;
}
