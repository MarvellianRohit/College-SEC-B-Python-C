/*
Question: Write a C program to input three integers and calculate their average
using arithmetic operators.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables for three numbers and the average
  int num1, num2, num3;
  float average;

  // Prompt user for three numbers
  printf("Enter three integers: ");
  // Read the three integers
  scanf("%d %d %d", &num1, &num2, &num3);

  // Calculate average using formula: (sum of numbers) / count
  // Multiply by 3.0 to force floating point division
  average = (num1 + num2 + num3) / 3.0;

  // Print the average
  printf("Average = %.2f\n", average);

  // Return 0 for success
  return 0;
}
