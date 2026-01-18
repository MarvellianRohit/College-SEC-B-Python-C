/*
Question: Write a program to swap two numbers using only arithmetic operators
(no temporary variable).
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare two variables
  int a, b;

  // Prompt user for input
  printf("Enter value for a: ");
  scanf("%d", &a);
  printf("Enter value for b: ");
  scanf("%d", &b);

  // Display before swapping
  printf("\nBefore Swapping: a = %d, b = %d\n", a, b);

  // Logic to swap using arithmetic operators (+ and -)
  // Step 1: a becomes sum of a and b
  a = a + b;
  // Step 2: b becomes (a + b) - b which is original a
  b = a - b;
  // Step 3: a becomes (a + b) - a which is original b
  a = a - b;

  // Display after swapping
  printf("After Swapping:  a = %d, b = %d\n", a, b);

  // Return 0 for success
  return 0;
}
