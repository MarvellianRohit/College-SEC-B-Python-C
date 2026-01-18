// Include the standard input/output library
#include <stdio.h>

// Main function where program execution begins
int main() {
  // Declare variables for calculate celsius and fahrenheit
  float celsius, fahrenheit;

  // Prompt the user to enter temperature in Celsius
  printf("Enter temperature in Celsius: ");
  // Read the celsius value
  scanf("%f", &celsius);

  // Calculate Fahrenheit using the formula: (Celsius * 9/5) + 32
  fahrenheit = (celsius * 9 / 5) + 32;

  // Print the calculated temperature in Fahrenheit
  printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);

  // Return 0 to indicate successful execution
  return 0;
}
