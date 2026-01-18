/*
Question: Write a C program to print numbers from N down to 1 using a for loop.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variable
  int N, i;

  // Prompt user for N
  printf("Enter value of N: ");
  scanf("%d", &N);

  printf("Numbers from %d down to 1:\n", N);

  // Loop starting from N, decrementing i in each iteration until i >= 1
  for (i = N; i >= 1; i--) {
    // Print current value of i
    printf("%d ", i);
  }
  printf("\n");

  // Return 0 for success
  return 0;
}
