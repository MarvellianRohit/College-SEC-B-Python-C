/*
Question: Write a program that takes three integers and uses the ternary
operator to find and print the largest number.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  int n1, n2, n3, max;

  // Prompt user for inputs
  printf("Enter three integers: ");
  scanf("%d %d %d", &n1, &n2, &n3);

  // Use nested ternary operators to find max
  // Check if n1 > n2
  // If true, check if n1 > n3. If yes, max=n1, else max=n3
  // If false, check if n2 > n3. If yes, max=n2, else max=n3
  max = (n1 > n2) ? ((n1 > n3) ? n1 : n3) : ((n2 > n3) ? n2 : n3);

  // Print the largest number
  printf("The largest number is %d\n", max);

  // Return 0 for success
  return 0;
}
