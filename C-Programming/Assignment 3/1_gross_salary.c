/*
Question: Write a C program to input basic salary of an employee and calculate
its Gross salary according to following: Basic Salary <= 10000 : HRA = 20%, DA =
80% Basic Salary <= 20000 : HRA = 25%, DA = 90% Basic Salary > 20000  : HRA =
30%, DA = 95%
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables for basic salary, HRA, DA, and gross salary
  float basic, hra, da, gross;

  // Prompt user for basic salary
  printf("Enter basic salary: ");
  // Read basic salary
  scanf("%f", &basic);

  // Check if basic salary is less than or equal to 10000
  if (basic <= 10000) {
    // HRA is 20% of basic
    hra = basic * 0.20;
    // DA is 80% of basic
    da = basic * 0.80;
  }
  // Check if basic salary is less than or equal to 20000
  else if (basic <= 20000) {
    // HRA is 25% of basic
    hra = basic * 0.25;
    // DA is 90% of basic
    da = basic * 0.90;
  }
  // If basic salary is greater than 20000
  else {
    // HRA is 30% of basic
    hra = basic * 0.30;
    // DA is 95% of basic
    da = basic * 0.95;
  }

  // Calculate Gross Salary = Basic + HRA + DA
  gross = basic + hra + da;

  // Print calculated Gross Salary
  printf("Gross Salary = %.2f\n", gross);

  // Return 0 for success
  return 0;
}
