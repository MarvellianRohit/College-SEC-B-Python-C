/*
Question: Write a program to take a character input and check whether it is a
capital letter using relational and logical operators.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare character variable
  char ch;

  // Prompt user for input
  printf("Enter a character: ");
  scanf(" %c", &ch); // Space before %c handles whitespace/newlines

  // Check if character ASCII value is between 'A' and 'Z'
  // 'A' is 65 and 'Z' is 90
  if (ch >= 'A' && ch <= 'Z') {
    printf("'%c' is a Capital Letter.\n", ch);
  } else {
    printf("'%c' is NOT a Capital Letter.\n", ch);
  }

  // Return 0 for success
  return 0;
}
