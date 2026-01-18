/*
Question: Write a function to find the average of elements in an array.
*/

// Include standard input/output library
#include <stdio.h>

// Function to calculate average
float calculateAverage(int arr[], int n) {
  int sum = 0;
  // Sum all elements
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  // Return average (sum / count)
  // Cast to float for decimal application
  return (float)sum / n;
}

// Main function
int main() {
  // Declare variables
  int n;

  // Prompt for array size
  printf("Enter size of array: ");
  scanf("%d", &n);

  int arr[n];
  // Input array elements
  printf("Enter %d integers:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Call function and print result
  printf("Average of elements: %.2f\n", calculateAverage(arr, n));

  // Return 0 for success
  return 0;
}
