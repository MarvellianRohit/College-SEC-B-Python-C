/*
Question: Write a program that keeps taking numbers from the user and adds them
to the sum until the user enters 0 (use do-while).
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  double number, sum = 0.0;

  // Do-while loop
  do {
    // Prompt for input
    printf("Enter a number (enter 0 to stop): ");
    scanf("%lf", &number);

    // Add to sum
    sum += number;
  } while (number != 0.0); // Continue if input is not 0

  // Print final sum
  printf("Total Sum = %.2f\n", sum);

  // Return 0 for success
  return 0;
}
