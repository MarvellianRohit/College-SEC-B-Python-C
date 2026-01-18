// Include the standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare integer variables for radius and volume
  // Note: Using integer arithmetic typically results in loss of precision
  int radius, volume;

  // Prompt user for radius
  printf("Enter radius of the sphere (integer): ");
  scanf("%d", &radius);

  // Calculate volume using integer arithmetic
  // Standard Formula: (4/3) * PI * r^3
  // Integer Approximation: (4 * 22 * r * r * r) / (3 * 7)
  // We multiply first to minimize precision loss before division
  volume = (4 * 22 * radius * radius * radius) / (3 * 7);

  // Print the calculated volume
  printf("Volume of sphere (Integer Arithmetic): %d\n", volume);

  // Return 0 for success
  return 0;
}
