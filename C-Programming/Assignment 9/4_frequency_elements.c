/*
Question: Frequency of Elements: This program uses functions to find the
frequency of each element, plus the most and least frequent elements.
*/

// Include standard input/output library
#include <stdio.h>

// Function to find frequency
void findFrequency(int arr[], int n) {
  // Array to store frequency, initialized to -1
  // Assuming max element value is smaller than size or using parallel logic
  // A simpler approach O(n^2) without hashing for basic C

  int visited[n];
  // Initialize visited array to 0
  for (int i = 0; i < n; i++)
    visited[i] = 0;

  int maxFreq = -1, minFreq = n + 1;
  int maxElement, minElement;

  printf("\nElement Frequency:\n");

  for (int i = 0; i < n; i++) {
    // Skip if already counted
    if (visited[i] == 1)
      continue;

    int count = 1;
    for (int j = i + 1; j < n; j++) {
      if (arr[i] == arr[j]) {
        visited[j] = 1; // Mark as visited
        count++;
      }
    }

    printf("%d occurs %d times\n", arr[i], count);

    // Update most frequent
    if (count > maxFreq) {
      maxFreq = count;
      maxElement = arr[i];
    }
    // Update least frequent
    if (count < minFreq) {
      minFreq = count;
      minElement = arr[i];
    }
  }

  printf("\nMost Frequent Element: %d (Frequency: %d)\n", maxElement, maxFreq);
  printf("Least Frequent Element: %d (Frequency: %d)\n", minElement, minFreq);
}

// Main function
int main() {
  int n;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter %d integers:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Call function
  findFrequency(arr, n);

  return 0;
}
