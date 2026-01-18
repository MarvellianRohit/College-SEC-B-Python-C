/*
Question: Write a program that calculates the area of a rectangle using the
formula length * breadth using arithmetic operators.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare float variables for length, breadth, and area
  float length, breadth, area;

  // Prompt user for length
  printf("Enter length: ");
  scanf("%f", &length);

  // Prompt user for breadth
  printf("Enter breadth: ");
  scanf("%f", &breadth);

  // Calculate Area
  area = length * breadth;

  // Print Area
  printf("Area of Rectangle = %.2f\n", area);

  // Return 0 for success
  return 0;
}
