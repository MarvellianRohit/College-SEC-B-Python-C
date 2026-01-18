/*
Question: Write a C program to input an amount in rupees and convert it to paise
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables for rupees and paise
  float rupees, paise;

  // Prompt user for amount in Rupees
  printf("Enter amount in Rupees: ");
  // Read rupees
  scanf("%f", &rupees);

  // Calculate paise (1 Rupee = 100 Paise)
  paise = rupees * 100;

  // Print the result
  printf("%.2f Rupees = %.0f Paise\n", rupees, paise);

  // Return 0 for success
  return 0;
}
