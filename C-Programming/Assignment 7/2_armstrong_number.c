/*
Question: Write a program to check if a number is an Armstrong number (e.g., 153
= 1^3 + 5^3 + 3^3).
*/

// Include standard input/output library
#include <stdio.h>
// Include math library for pow() function
#include <math.h>

// Main function where execution starts
int main() {
  // Declare integer variable 'num' to store user input
  int num;
  // Declare 'originalNum' to preserve the input value for comparison
  int originalNum;
  // Declare 'remainder' to store the last digit extracted
  int remainder;
  // Declare 'result' to store the sum of cubes and initialize it to 0
  // Using double for result to verify against pow output, or cast back to int
  int result = 0;

  // Prompt the user to enter a three-digit integer
  printf("Enter a three-digit integer: ");
  // Read the integer input from keyboard and store it in 'num'
  scanf("%d", &num);

  // Store the value of 'num' in 'originalNum' so we can compare later
  originalNum = num;

  // Start a while loop that continues as long as 'originalNum' is not 0
  while (originalNum != 0) {
    // Calculate the last digit of 'originalNum'
    remainder = originalNum % 10;

    // Calculate the cube of the remainder using pow() function
    // pow returns a double, so we add it to result (implicit conversion or
    // explicit use appropriate types) Check for specific Assignment
    // requirement: 3-digit number means power is 3
    result += round(pow(remainder, 3));

    // Remove the last digit from 'originalNum' by dividing by 10
    originalNum /= 10;
  }

  // Check if the calculated 'result' matches the user's initial input 'num'
  if (result == num) {
    // If they match, print that it is an Armstrong number
    printf("%d is an Armstrong number.\n", num);
  } else {
    // If they don't match, print that it is not an Armstrong number
    printf("%d is not an Armstrong number.\n", num);
  }

  // Return 0 to the operating system to indicate successful execution
  return 0;
}
