// Include the standard input/output library
#include <stdio.h>

// Main function where program execution begins
int main() {
  // Declare variables for two numbers and a temporary variable
  int num1, num2, temp;

  // Prompt the user to enter the first number
  printf("Enter the first number: ");
  // Read the first number
  scanf("%d", &num1);

  // Prompt the user to enter the second number
  printf("Enter the second number: ");
  // Read the second number
  scanf("%d", &num2);

  // Display the numbers before swapping
  printf("\nBefore Swapping: num1 = %d, num2 = %d\n", num1, num2);

  // Step 1: Assign the value of num1 to temp
  temp = num1;

  // Step 2: Assign the value of num2 to num1
  num1 = num2;

  // Step 3: Assign the value of temp (original num1) to num2
  num2 = temp;

  // Display the numbers after swapping
  printf("After Swapping:  num1 = %d, num2 = %d\n", num1, num2);

  // Return 0 to indicate successful execution
  return 0;
}
