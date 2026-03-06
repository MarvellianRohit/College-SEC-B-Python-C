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
Enter a number to print its table: Multiplication Table of 0:
0 * 1 = 0
0 * 2 = 0
0 * 3 = 0
0 * 4 = 0
0 * 5 = 0
0 * 6 = 0
0 * 7 = 0
0 * 8 = 0
0 * 9 = 0
0 * 10 = 0
*/
