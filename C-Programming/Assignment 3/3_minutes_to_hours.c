/*
Question: Write a C program to input total minutes and convert to hour.
(We will convert to Hours and Minutes for clarity)
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables for total minutes, hours, and remaining minutes
  int totalMinutes, hours, minutes;

  // Prompt user for total minutes
  printf("Enter total minutes: ");
  // Read total minutes
  scanf("%d", &totalMinutes);

  // Calculate hours by dividing total minutes by 60
  hours = totalMinutes / 60;

  // Calculate remaining minutes using modulo operator
  minutes = totalMinutes % 60;

  // Print the result
  printf("%d minutes = %d Hours and %d Minutes\n", totalMinutes, hours,
         minutes);

  // Return 0 for success
  return 0;
}
