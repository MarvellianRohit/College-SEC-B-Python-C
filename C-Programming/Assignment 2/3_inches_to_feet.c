// Include the standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables for total inches, feet, and remaining inches
  int totalInches, feet, inches;

  // Prompt user for total inches
  printf("Enter total inches: ");
  // Read total inches
  scanf("%d", &totalInches);

  // Calculate feet by integer division (12 inches = 1 foot)
  feet = totalInches / 12;

  // Calculate remaining inches using modulo operator
  inches = totalInches % 12;

  // Print the result in Feet and Inches format
  printf("%d inches is equal to %d feet and %d inches\n", totalInches, feet,
         inches);

  // Return 0 for success
  return 0;
}
