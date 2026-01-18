/*
Question: Write a C program to input marks and display the grade:
Marks >= 90 -> Grade A
Marks >= 75 -> Grade B
Marks >= 50 -> Grade C
Otherwise -> Fail
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variable for marks
  int marks;

  // Prompt user for input
  printf("Enter marks: ");
  scanf("%d", &marks);

  // Check conditions using if-else ladder
  if (marks >= 90) {
    printf("Grade A\n");
  } else if (marks >= 75) {
    printf("Grade B\n");
  } else if (marks >= 50) {
    printf("Grade C\n");
  } else {
    printf("Fail\n");
  }

  // Return 0 for success
  return 0;
}
