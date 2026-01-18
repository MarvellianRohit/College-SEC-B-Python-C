/*
Question: Write a program to evaluate and print the result of the expression: (a
+ b) * c / d % e
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare integer variables
  int a, b, c, d, e, result;

  printf("Enter 5 integers for a, b, c, d, e: ");
  // Read 5 integers
  scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

  // Evaluate expression: (a + b) * c / d % e
  // Order of operations (Precedence):
  // 1. Parentheses (a + b)
  // 2. Multiplication (*), Division (/), Modulo (%) have same precedence,
  // evaluated Left-to-Right.

  if (d == 0 || e == 0) {
    printf("Error: Division or Modulo by zero is not allowed.\n");
  } else {
    result = (a + b) * c / d % e;
    printf("Result of (%d + %d) * %d / %d %% %d is: %d\n", a, b, c, d, e,
           result);
  }

  // Return 0 for success
  return 0;
}
