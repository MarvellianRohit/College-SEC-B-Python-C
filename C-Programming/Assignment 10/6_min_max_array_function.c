/*
Question: Write a function to find the largest and smallest elements in an
array.
*/

// Include standard input/output library
#include <stdio.h>

// Function to find largest and smallest
// Using pointers to return multiple values
void findMinMax(int arr[], int n, int *min, int *max) {
  // Initialize min and max with the first element
  *min = arr[0];
  *max = arr[0];

  // Iterate through the rest of the array
  for (int i = 1; i < n; i++) {
    // Check if current element is smaller than min
    if (arr[i] < *min) {
      *min = arr[i];
    }
    // Check if current element is larger than max
    if (arr[i] > *max) {
      *max = arr[i];
    }
  }
}

// Main function
int main() {
  // Declare variables
  int n, min, max;

  // Prompt for array size
  printf("Enter size of array: ");
  scanf("%d", &n);

  int arr[n];
  // Input array elements
  printf("Enter %d integers:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Call function
  // Pass references of min and max variables
  findMinMax(arr, n, &min, &max);

  // Print results
  printf("Smallest element: %d\n", min);
  printf("Largest element: %d\n", max);

  // Return 0 for success
  return 0;
}
