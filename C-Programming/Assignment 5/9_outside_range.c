/*
Question: Write a program to input a number and check whether it lies outside
the range 50 to 100 using logical NOT (!) and relational operators.
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

  // Range 50 to 100 inclusive is (num >= 50 && num <= 100)
  // To check OUTSIDE range using NOT (!), we simply negate the inside
  // condition.
  // !(num >= 50 && num <= 100) means it is NOT in the range [50, 100].

  if (!(num >= 50 && num <= 100)) {
    printf("%d lies OUTSIDE the range 50 to 100.\n", num);
  } else {
    printf("%d lies INSIDE the range 50 to 100.\n", num);
  }

  // Return 0 for success
  return 0;
}
