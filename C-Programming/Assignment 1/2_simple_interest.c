// Include the standard input/output library
#include <stdio.h>

// Main function where program execution begins
int main() {
  // Declare variables for principal, rate, time, and simple interest
  float principal, rate, time, interest;

  // Prompt the user to enter the principal amount
  printf("Enter the principal amount: ");
  // Read the principal amount
  scanf("%f", &principal);

  // Prompt the user to enter the rate of interest
  printf("Enter the rate of interest: ");
  // Read the rate of interest
  scanf("%f", &rate);

  // Prompt the user to enter the time period in years
  printf("Enter the time in years: ");
  // Read the time period
  scanf("%f", &time);

  // Calculate simple interest using the formula: SI = (P * R * T) / 100
  interest = (principal * rate * time) / 100;

  // Print the calculated simple interest
  printf("Simple Interest: %.2f\n", interest);

  // Return 0 to indicate successful execution
  return 0;
}
