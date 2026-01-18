// Include the standard input/output library
#include <stdio.h>
// Include math library for pow() function
#include <math.h>

// Main function
int main() {
  // Declare variables for Principal, Rate, Time, amount, and CI
  float principal, rate, time, amount, ci;

  // Prompt user for principal
  printf("Enter principal amount: ");
  scanf("%f", &principal);

  // Prompt user for rate
  printf("Enter annual rate of interest: ");
  scanf("%f", &rate);

  // Prompt user for time
  printf("Enter time in years: ");
  scanf("%f", &time);

  // Calculate Amount using formula: A = P(1 + R/100)^t
  amount = principal * pow((1 + rate / 100), time);

  // Calculate Compound Interest = Amount - Principal
  ci = amount - principal;

  // Print the Compound Interest
  printf("Compound Interest: %.2f\n", ci);

  // Print the Total Amount
  printf("Total Amount: %.2f\n", amount);

  // Return 0 for success
  return 0;
}
