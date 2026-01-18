/*
Question: Write a C program to check whether a given year is a leap year or not.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare integer variable for year
  int year;

  // Prompt user for input
  printf("Enter a year: ");
  scanf("%d", &year);

  // Leap year logic:
  // 1. If divisible by 400, it is a leap year.
  // 2. Else if divisible by 100, it is NOT a leap year.
  // 3. Else if divisible by 4, it IS a leap year.
  // 4. Otherwise, it is not a leap year.

  if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
    printf("%d is a Leap Year.\n", year);
  } else {
    printf("%d is NOT a Leap Year.\n", year);
  }

  // Return 0 for success
  return 0;
}
