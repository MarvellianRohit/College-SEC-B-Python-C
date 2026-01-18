/*
Question: Write a program to input a number and print:
1 if even,
0 if odd
using only bitwise AND (&) operator.
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

  // Bitwise AND with 1 returns 1 if the number is odd, and 0 if even.
  // The question asks for 1 if even, 0 if odd.
  // So we need to reverse the logic.
  // (num & 1) gives 1 for odd, 0 for even.
  // We can use logical NOT (!) or subtract from 1 to flip it.
  // Let's use (num & 1) check directly in logic or arithmetic.

  // Logic:
  // If num is odd: num & 1 is 1 -> we want to print 0
  // If num is even: num & 1 is 0 -> we want to print 1

  // Implementation: print 1 - (num & 1)
  printf("Result: %d\n", 1 - (num & 1));

  // Return 0 for success
  return 0;
}
