/*
Question: Write a C program that takes an array of integers from the user and:
i. Displays the frequency of each unique number.
ii. Finds the number that occurs most frequently.
iii. Finds the number that occurs least frequently.
iv. Use functions for each task.
*/

// Include standard input/output library
#include <stdio.h>

// Function to display frequency of each element
void displayFrequency(int arr[], int n) {
  // Create a visited array to track processed elements
  int visited[n];

  // Initialize visited array to 0
  for (int i = 0; i < n; i++)
    visited[i] = 0;

  printf("\n--- Frequency of Each Number ---\n");
  // Loop through each element
  for (int i = 0; i < n; i++) {
    // Skip if already processed
    if (visited[i] == 1)
      continue;

    // Initialize count for current element
    int count = 1;
    // Check remaining elements for duplicates
    for (int j = i + 1; j < n; j++) {
      // If match found
      if (arr[i] == arr[j]) {
        // Mark as visited
        visited[j] = 1;
        // Increment count
        count++;
      }
    }
    // Print the element and its frequency
    printf("%d: %d times\n", arr[i], count);
  }
}

// Function to find the most frequent element
void findMostFrequent(int arr[], int n) {
  // Initialize maxCount and result variable
  int maxCount = 0, res = -1;

  // Create visited array
  int visited[n];
  for (int i = 0; i < n; i++)
    visited[i] = 0;

  // Loop through each element
  for (int i = 0; i < n; i++) {
    // Skip visited
    if (visited[i] == 1)
      continue;

    int count = 1;
    // Count occurrences
    for (int j = i + 1; j < n; j++) {
      if (arr[i] == arr[j]) {
        visited[j] = 1;
        count++;
      }
    }
    // Update maxCount and result if current count is higher
    if (count > maxCount) {
      maxCount = count;
      res = arr[i];
    }
  }
  // Print the result
  printf("\nMost Frequent Element: %d (Frequency: %d)\n", res, maxCount);
}

// Function to find the least frequent element
void findLeastFrequent(int arr[], int n) {
  // Initialize minCount with a value larger than any possible count
  int minCount = n + 1, res = -1;

  // Create visited array
  int visited[n];
  for (int i = 0; i < n; i++)
    visited[i] = 0;

  // Loop through each element
  for (int i = 0; i < n; i++) {
    // Skip visited
    if (visited[i] == 1)
      continue;

    int count = 1;
    // Count occurrences
    for (int j = i + 1; j < n; j++) {
      if (arr[i] == arr[j]) {
        visited[j] = 1;
        count++;
      }
    }
    // Update minCount and result if current count is lower
    if (count < minCount) {
      minCount = count;
      res = arr[i];
    }
  }
  // Print the result
  printf("Least Frequent Element: %d (Frequency: %d)\n", res, minCount);
}

// Main function
int main() {
  // Declare variable for size
  int n;
  // Prompt number of elements
  printf("Enter size of array: ");
  scanf("%d", &n);

  // Declare array of size n (Variable Length Array)
  int arr[n];

  // Input elements
  printf("Enter elements of array:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Call functions to perform analysis
  displayFrequency(arr, n);
  findMostFrequent(arr, n);
  findLeastFrequent(arr, n);

  // Return 0 for success
  return 0;
}
