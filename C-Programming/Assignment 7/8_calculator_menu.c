/*
Question: Write a program that uses a do-while loop to repeatedly display a menu
(Add, Subtract, Multiply, Divide, Exit) until the user chooses Exit.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables for choice and numbers
  int choice;
  float num1, num2, result;

  // Do-while loop guarantees the loop runs at least once
  do {
    // Display Menu
    printf("\n--- Calculator Menu ---\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Check if user wants to exit
    if (choice == 5) {
      printf("Exiting program.\n");
      break; // Break loop immediately
    }

    // Check if choice is valid
    if (choice >= 1 && choice <= 4) {
      printf("Enter two numbers: ");
      scanf("%f %f", &num1, &num2);
    } else {
      printf("Invalid choice! Please try again.\n");
      continue; // Skip rest of loop and show menu again
    }

    // Perform operation based on choice
    switch (choice) {
    case 1:
      result = num1 + num2;
      printf("Result: %.2f\n", result);
      break;
    case 2:
      result = num1 - num2;
      printf("Result: %.2f\n", result);
      break;
    case 3:
      result = num1 * num2;
      printf("Result: %.2f\n", result);
      break;
    case 4:
      // Check for division by zero
      if (num2 != 0) {
        result = num1 / num2;
        printf("Result: %.2f\n", result);
      } else {
        printf("Error: Division by zero.\n");
      }
      break;
    }
  } while (choice != 5);

  // Return 0 for success
  return 0;
}
