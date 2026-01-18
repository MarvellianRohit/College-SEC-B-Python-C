/*
Question: Write a program to demonstrate the difference between = and == with a
clear output.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare integer variables a and b with initial values
  int a = 10, b = 20;

  // Print the initial values
  printf("Initial values: a = 10, b = 20\n\n");

  // Demonstration of Equality Operator (==)
  // Print label for equality check
  printf("Using Equality Operator (a == b):\n");

  // Check if a is equal to b
  if (a == b) {
    // If true, print that they are equal
    printf("Result: a is equal to b (True)\n");
  } else {
    // If false, print that they are not equal
    printf("Result: a is NOT equal to b (False)\n"); // This will execute
  }

  // Demonstration of Assignment Operator (=)
  // Print label for assignment check
  printf("\nUsing Assignment Operator (a = b):\n");

  // The expression (a = b) assigns b to a, and evaluates to the new value of a
  // (20) Since 20 is non-zero, the condition is true. We use double parentheses
  // (( )) to silence the compiler warning about assignment in boolean context.
  if ((a = b)) {
    // Print that assignment occurred and the new value of a
    printf("Result: a has been assigned the value of b. New a = %d\n", a);
  }

  // Return 0 for success
  return 0;
}
