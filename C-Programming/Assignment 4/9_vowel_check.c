/*
Question: Write a program to check whether a character is a vowel (uppercase or
lowercase) using logical and relational operators.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare char variable
  char ch;

  // Prompt user for character
  printf("Enter a character: ");
  // Read character (note space before %c to consume any newline buffer)
  scanf(" %c", &ch);

  // Check lowercase vowels OR uppercase vowels
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
      ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
    printf("%c is a vowel.\n", ch);
  } else {
    printf("%c is not a vowel.\n", ch);
  }

  // Return 0 for success
  return 0;
}
