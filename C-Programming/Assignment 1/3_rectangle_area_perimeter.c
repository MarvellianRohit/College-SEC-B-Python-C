// Include the standard input/output library
#include <stdio.h>

// Main function where program execution begins
int main() {
  // Declare variables for length, width, area, and perimeter
  float length, width, area, perimeter;

  // Prompt the user to enter the length of the rectangle
  printf("Enter the length of the rectangle: ");
  // Read the length
  scanf("%f", &length);

  // Prompt the user to enter the width of the rectangle
  printf("Enter the width of the rectangle: ");
  // Read the width
  scanf("%f", &width);

  // Calculate the area using the formula: Area = length * width
  area = length * width;

  // Calculate the perimeter using the formula: Perimeter = 2 * (length + width)
  perimeter = 2 * (length + width);

  // Print the calculated area
  printf("Area of the rectangle: %.2f\n", area);

  // Print the calculated perimeter
  printf("Perimeter of the rectangle: %.2f\n", perimeter);

  // Return 0 to indicate successful execution
  return 0;
}
