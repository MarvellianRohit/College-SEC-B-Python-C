/*
Question: Write a program to check if a number is a multiple of both 3 and 5
using logical operators.
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

  // Check divisibility by both 3 and 5 using logical AND (&&)
  // condition: (num % 3 == 0) AND (num % 5 == 0)
  if ((num % 3 == 0) && (num % 5 == 0)) {
    printf("%d is a multiple of both 3 and 5.\n", num);
  } else {
    printf("%d is NOT a multiple of both 3 and 5.\n", num);
  }

  // Return 0 for success
  return 0;
}
