/*
Question: Write a C program to print the multiplication table of a number.
*/

// Include standard input/output library

#include <stdio.h>

// Main function

int main() {

  // Declare variables for number and loop counter

  int num, i;

  // Prompt user for input

  printf("Enter a number to print its table: ");

  // Read number

  scanf("%d", &num);

  // Loop from 1 to 10

  printf("Multiplication Table of %d:\n", num);

  for (i = 1; i <= 10; ++i) {

    // Print the product in format: num * i = result

    printf("%d * %d = %d\n", num, i, num * i);

  }

  // Return 0 for success

  return 0;

}

/*
Output:
Enter a number to print its table: Multiplication Table of 5:
5 * 1 = 5
5 * 2 = 10
5 * 3 = 15
5 * 4 = 20
5 * 5 = 25
5 * 6 = 30
5 * 7 = 35
5 * 8 = 40
5 * 9 = 45
5 * 10 = 50
*/
