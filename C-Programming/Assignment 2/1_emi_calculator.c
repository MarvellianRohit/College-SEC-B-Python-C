// Include the standard input/output library
#include <stdio.h>
// Include math library for the power function pow()
#include <math.h>

// Main function
int main() {
  // Declare variables for Principal, Rate, Time, and EMI
  float principal, rate, time, emi;

  // Prompt user for principal amount
  printf("Enter principal amount: ");
  // Read principal
  scanf("%f", &principal);

  // Prompt user for annual interest rate
  printf("Enter annual interest rate: ");
  // Read rate
  scanf("%f", &rate);

  // Prompt user for time in years
  printf("Enter time in years: ");
  // Read time
  scanf("%f", &time);

  // Convert annual rate to monthly rate (rate / 12 / 100)
  rate = rate / (12 * 100);
  // Convert time in years to number of months
  time = time * 12;

  // Calculate EMI using formula: P * R * (1+R)^N / ((1+R)^N - 1)
  emi = (principal * rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1);

  // Print the calculated EMI
  printf("Monthly EMI: %.2f\n", emi);

  // Return 0 for success
  return 0;
}
