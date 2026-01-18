/*
Question: Write a C program to perform the following on an integer array (Each
task should be implemented as a function): Reverse the array Remove duplicate
elements Find the sum of even numbers and odd numbers separately Rotate the
array by k positions (user input).
*/

// Include standard input/output library
#include <stdio.h>

// Function to reverse and print the array
void reverseArray(int arr[], int n) {
  printf("\nReversed Array: ");
  // Loop from the last element to the first
  for (int i = n - 1; i >= 0; i--) {
    // Print current element
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Function to remove duplicates and print result
void removeDuplicates(int arr[], int n) {
  printf("\nArray after removing duplicates: ");
  // Create visited array to track duplicates
  int visited[n];
  // Initialize visited array
  for (int i = 0; i < n; i++)
    visited[i] = 0;

  // Loop through elements
  for (int i = 0; i < n; i++) {
    // If already printed/visited, skip
    if (visited[i] == 1)
      continue;

    // Print unique element
    printf("%d ", arr[i]);

    // Mark all subsequent occurrences as visited
    for (int j = i + 1; j < n; j++) {
      if (arr[i] == arr[j])
        visited[j] = 1;
    }
  }
  printf("\n");
}

// Function to find sum of even and odd numbers
void sumEvenOdd(int arr[], int n) {
  // Initialize sums
  int evenSum = 0, oddSum = 0;

  // Loop through array
  for (int i = 0; i < n; i++) {
    // Check if even
    if (arr[i] % 2 == 0)
      evenSum += arr[i];
    else
      // Else it is odd
      oddSum += arr[i];
  }
  // Print sums
  printf("\nSum of Even numbers: %d\n", evenSum);
  printf("Sum of Odd numbers: %d\n", oddSum);
}

// Function to rotate array by k positions
void rotateArray(int arr[], int n) {
  int k;
  // Prompt for k
  printf("\nEnter number of positions to rotate (right): ");
  scanf("%d", &k);

  // Normalize k (handles k > n)
  k = k % n;

  printf("Rotated Array: ");
  // Print elements from index n-k to end (the part that moves to front)
  for (int i = n - k; i < n; i++) {
    printf("%d ", arr[i]);
  }
  // Print elements from index 0 to n-k-1 (the part that shifts right)
  for (int i = 0; i < n - k; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Main function
int main() {
  int n, choice;
  // Prompt for array size
  printf("Enter number of elements: ");
  scanf("%d", &n);

  // Declare VLA
  int arr[n];

  // Input elements
  printf("Enter elements:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Menu loop
  do {
    printf("\n--- Array Operations ---\n");
    printf("1. Reverse Array\n");
    printf("2. Remove Duplicates\n");
    printf("3. Sum of Even and Odd\n");
    printf("4. Rotate Array\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    // Handle user choice
    switch (choice) {
    case 1:
      reverseArray(arr, n);
      break;
    case 2:
      removeDuplicates(arr, n);
      break;
    case 3:
      sumEvenOdd(arr, n);
      break;
    case 4:
      rotateArray(arr, n);
      break;
    case 5:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice!\n");
    }
  } while (choice != 5);

  // Return 0 for success
  return 0;
}
