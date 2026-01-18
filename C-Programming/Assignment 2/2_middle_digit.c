// Include the standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variable for the number and the middle digit
  int num, middleDigit;

  // Prompt user to enter a 3-digit number
  printf("Enter a 3-digit number: ");
  // Read the number
  scanf("%d", &num);

  // Logic to extract middle digit:
  // 1. Divide by 10 to remove the last digit (e.g., 123 / 10 = 12)
  // 2. Modulo 10 to get the new last digit (e.g., 12 % 10 = 2)
  middleDigit = (num / 10) % 10;

  // Print the middle digit
  printf("The middle digit is: %d\n", middleDigit);

  // Return 0 for success
  return 0;
}
