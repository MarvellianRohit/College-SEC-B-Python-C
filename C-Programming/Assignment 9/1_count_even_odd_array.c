/*
Question: Count Even and Odd Numbers in a Array
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  int n, i, evenCount = 0, oddCount = 0;

  // Prompt for array size
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  // Declare array of size n
  int arr[n];

  // Input array elements
  printf("Enter %d integers:\n", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Traverse array to count even and odd numbers
  for (i = 0; i < n; i++) {
    // Check if divisible by 2
    if (arr[i] % 2 == 0) {
      evenCount++;
    } else {
      oddCount++;
    }
  }

  // Print results
  printf("Total Even numbers: %d\n", evenCount);
  printf("Total Odd numbers: %d\n", oddCount);

  // Return 0 for success
  return 0;
}
