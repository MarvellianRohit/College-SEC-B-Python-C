/*
Question: Write a program that accepts three numbers and prints the greatest
among them using relational and logical operators.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare three integer variables
  int n1, n2, n3;

  // Prompt user for inputs
  printf("Enter three numbers: ");
  scanf("%d %d %d", &n1, &n2, &n3);

  // Logic to find the greatest
  // Check if n1 is greater than both n2 AND n3
  if (n1 >= n2 && n1 >= n3) {
    printf("%d is the greatest.\n", n1);
  }
  // Check if n2 is greater than both n1 AND n3
  else if (n2 >= n1 && n2 >= n3) {
    printf("%d is the greatest.\n", n2);
  }
  // If neither, then n3 must be the greatest
  else {
    printf("%d is the greatest.\n", n3);
  }

  // Return 0 for success
  return 0;
}
