/*
Question: Write a C program to check whether a number is even or odd.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare integer variable
  int num;

  // Prompt user for input
  printf("Enter an integer: ");
  // Read integer
  scanf("%d", &num);

  // Check divisibility by 2
  if (num % 2 == 0) {
    // If remainder is 0, it is even
    printf("%d is even.\n", num);
  } else {
    // If remainder is not 0, it is odd
    printf("%d is odd.\n", num);
  }

  // Return 0 for success
  return 0;
}
