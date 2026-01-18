/*
Question: Monthly Temperatures: This program uses functions to analyze 30 days
of temperature data.
*/

// Include standard input/output library
#include <stdio.h>

// Function to calculate average temperature
float calculateAverage(float temps[], int days) {
  float sum = 0;
  for (int i = 0; i < days; i++) {
    sum += temps[i];
  }
  return sum / days;
}

// Function to find highest temperature
float findHigh(float temps[], int days) {
  float max = temps[0];
  for (int i = 1; i < days; i++) {
    if (temps[i] > max) {
      max = temps[i];
    }
  }
  return max;
}

// Function to find lowest temperature
float findLow(float temps[], int days) {
  float min = temps[0];
  for (int i = 1; i < days; i++) {
    if (temps[i] < min) {
      min = temps[i];
    }
  }
  return min;
}

// Main function
int main() {
  int days = 30;
  float temps[30];

  printf("Enter temperature for 30 days:\n");
  // Taking input for 30 days
  // For testing, user might enter 30 values manually
  for (int i = 0; i < days; i++) {
    printf("Day %d: ", i + 1);
    scanf("%f", &temps[i]);
  }

  // Call functions
  float avg = calculateAverage(temps, days);
  float high = findHigh(temps, days);
  float low = findLow(temps, days);

  // Print analysis
  printf("\n--- Temperature Analysis ---\n");
  printf("Average Temperature: %.2f\n", avg);
  printf("Highest Temperature: %.2f\n", high);
  printf("Lowest Temperature:  %.2f\n", low);

  return 0;
}
