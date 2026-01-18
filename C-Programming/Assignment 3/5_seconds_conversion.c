/*
Question: Write a C program to input total seconds and convert to hours,
minutes, and seconds
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables for total seconds, hours, minutes, and remaining seconds
  int totalSeconds, hours, minutes, seconds;

  // Prompt user for total seconds
  printf("Enter total seconds: ");
  // Read total seconds
  scanf("%d", &totalSeconds);

  // Calculate hours (3600 seconds in an hour)
  hours = totalSeconds / 3600;

  // Calculate remaining seconds after extracting hours
  int remainingSeconds = totalSeconds % 3600;

  // Calculate minutes from the remaining seconds (60 seconds in a minute)
  minutes = remainingSeconds / 60;

  // Calculate final remaining seconds
  seconds = remainingSeconds % 60;

  // Print the result in HH:MM:SS format
  printf("%d seconds = %d Hours, %d Minutes, and %d Seconds\n", totalSeconds,
         hours, minutes, seconds);

  // Return 0 for success
  return 0;
}
