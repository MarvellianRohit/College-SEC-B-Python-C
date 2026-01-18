/*
Question: Write a function that takes an array and returns the second largest
element.
*/

// Include standard input/output library
#include <stdio.h>
// Include limits library for INT_MIN
#include <limits.h>

// Function to find second largest
int findSecondLargest(int arr[], int n) {
  int largest, secondLargest;

  // There should be at least two elements
  if (n < 2) {
    printf(" Invalid Input ");
    return INT_MIN;
  }

  largest = secondLargest = INT_MIN;

  for (int i = 0; i < n; i++) {
    // If current element is greater than largest
    if (arr[i] > largest) {
      secondLargest = largest;
      largest = arr[i];
    }
    // If current element is in between largest and secondLargest
    // and not equal to largest (to handle duplicates correctly)
    else if (arr[i] > secondLargest && arr[i] != largest) {
      secondLargest = arr[i];
    }
  }

  return secondLargest;
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

  // Call function
  int result = findSecondLargest(arr, n);

  if (result != INT_MIN)
    printf("The second largest element is %d\n", result);
  else
    printf("There is no second largest element.\n");

  // Return 0 for success
  return 0;
}
