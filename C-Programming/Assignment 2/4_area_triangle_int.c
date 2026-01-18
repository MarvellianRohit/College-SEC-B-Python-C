// Include the standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare integer variables for base, height, and area
  // Note: Using 'int' means any decimal part of the area will be truncated
  // (lost)
  int base, height, area;

  // Prompt user for base
  printf("Enter base of the triangle (integer): ");
  scanf("%d", &base);

  // Prompt user for height
  printf("Enter height of the triangle (integer): ");
  scanf("%d", &height);

  // Calculate area using integer arithmetic
  // Formula: (base * height) / 2
  // Since all variables are integers, the result will be an integer
  area = (base * height) / 2;

  // Print the calculated area
  printf("Area of triangle (Integer Arithmetic): %d\n", area);

  // Return 0 for success
  return 0;
}
