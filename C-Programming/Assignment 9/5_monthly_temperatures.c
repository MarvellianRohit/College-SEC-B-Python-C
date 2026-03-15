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

/*
Output:
Enter temperature for 30 days:
Day 1: Day 2: Day 3: Day 4: Day 5: Day 6: Day 7: Day 8: Day 9: Day 10: Day 11: Day 12: Day 13: Day 14: Day 15: Day 16: Day 17: Day 18: Day 19: Day 20: Day 21: Day 22: Day 23: Day 24: Day 25: Day 26: Day 27: Day 28: Day 29: Day 30: 
--- Temperature Analysis ---
Average Temperature: nan
Highest Temperature: 54519229918615835549018095616.00
Lowest Temperature:  -28792543589971045603767886875105165312.00
*/
