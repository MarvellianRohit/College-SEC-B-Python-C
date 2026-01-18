// Include the standard input/output library
#include <stdio.h>

// Main function where program execution begins
int main() {
  // Declare variables for radius, area, and perimeter
  float radius, area, perimeter;

  // Define the value of PI as a constant
  float PI = 3.14159;

  // Prompt the user to enter the radius of the circle
  printf("Enter the radius of the circle: ");

  // Read the radius entered by the user
  scanf("%f", &radius);

  // Calculate the area using the formula: Area = PI * radius * radius
  area = PI * radius * radius;

  // Calculate the perimeter (circumference) using the formula: Perimeter = 2 *
  // PI * radius
  perimeter = 2 * PI * radius;

  // Print the calculated area
  printf("Area of the circle: %.2f\n", area);

  // Print the calculated perimeter
  printf("Perimeter of the circle: %.2f\n", perimeter);

  // Return 0 to indicate successful execution
  return 0;
}
