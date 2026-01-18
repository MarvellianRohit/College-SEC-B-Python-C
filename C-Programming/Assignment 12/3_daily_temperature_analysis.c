/*
Question: Write a C program to store daily temperatures of a city for one month
(30 days). The program should (Use functions for each operation.): • Find the
average temperature of the month • Find the hottest and coldest days • Count how
many days temperature was above average
*/

// Include standard input/output library
#include <stdio.h>

// Function to calculate average temperature
float findAverage(float temps[], int n) {
  // Initialize sum variable
  float sum = 0;
  // Loop through all temperatures
  for (int i = 0; i < n; i++) {
    // Add temperature to sum
    sum += temps[i];
  }
  // Return average
  return sum / n;
}

// Function to find hottest and coldest days
void findHottestColdest(float temps[], int n) {
  // Initialize max and min with first day's temperature
  float max = temps[0], min = temps[0];
  // Initialize days tracking (1-based index)
  int maxDay = 1, minDay = 1;

  // Loop through remaining days
  for (int i = 1; i < n; i++) {
    // Check for new max
    if (temps[i] > max) {
      max = temps[i];
      maxDay = i + 1;
    }
    // Check for new min
    if (temps[i] < min) {
      min = temps[i];
      minDay = i + 1;
    }
  }
  // Print results
  printf("\nHottest Day: Day %d (%.2f°C)\n", maxDay, max);
  printf("Coldest Day: Day %d (%.2f°C)\n", minDay, min);
}

// Function to count days above average temperature
void countAboveAverage(float temps[], int n, float avg) {
  // Initialize counter
  int count = 0;
  // Loop through all temperatures
  for (int i = 0; i < n; i++) {
    // Check if temperature is greater than average
    if (temps[i] > avg)
      count++;
  }
  // Print the count
  printf("\nDays with temperature above average: %d\n", count);
}

// Main function
int main() {
  // Define constant for number of days
  int days = 30;
  // Declare array to store temperatures
  float temps[30];

  // Prompt user for input
  printf("Enter temperatures for 30 days:\n");

  // Loop to read temperatures
  for (int i = 0; i < days; i++) {
    // Prompt for specific day
    printf("Day %d: ", i + 1);
    scanf("%f", &temps[i]);
  }

  // Calculate average
  float avg = findAverage(temps, days);
  // Print average
  printf("\nAverage Temperature: %.2f°C\n", avg);

  // Find and print extremes
  findHottestColdest(temps, days);

  // Count and print days above average
  countAboveAverage(temps, days, avg);

  // Return 0 for success
  return 0;
}
