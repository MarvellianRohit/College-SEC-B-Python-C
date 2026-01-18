/*
Question: Write A c Program to do a bubble sort and other sorts
*/

// Include standard input/output library
#include <stdio.h>

// Function for Bubble Sort
void bubbleSort(int arr[], int n) {
  int temp;
  // Outer loop for passes (n-1 passes needed)
  for (int i = 0; i < n - 1; i++) {
    // Inner loop for comparison (up to unsorted portion)
    for (int j = 0; j < n - i - 1; j++) {
      // Compare adjacent elements
      if (arr[j] > arr[j + 1]) {
        // Swap if they are in wrong order
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// Function for Selection Sort
void selectionSort(int arr[], int n) {
  int minIdx, temp;
  // Loop to move boundary of unsorted subarray
  for (int i = 0; i < n - 1; i++) {
    // Assume first element is minimum
    minIdx = i;
    // Find the minimum element in unsorted array
    for (int j = i + 1; j < n; j++) {
      // If smaller element found, update minIdx
      if (arr[j] < arr[minIdx])
        minIdx = j;
    }
    // Swap the found minimum element with the first element of unsorted array
    temp = arr[minIdx];
    arr[minIdx] = arr[i];
    arr[i] = temp;
  }
}

// Function to print array elements
void printArray(int arr[], int n) {
  // Loop through array
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// Main function
int main() {
  int n, choice;
  // Prompt for size
  printf("Enter number of elements: ");
  scanf("%d", &n);

  // Declare arrays
  int arr[n], tempArr[n];

  // Input elements
  printf("Enter %d integers:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Menu loop
  do {
    printf("\n--- Sorting Algorithms ---\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    // Copy original array to tempArr for sorting so we don't lose original
    // order for other tests
    for (int i = 0; i < n; i++)
      tempArr[i] = arr[i];

    // Handle choice
    switch (choice) {
    case 1:
      // Call Bubble Sort
      bubbleSort(tempArr, n);
      printf("Bubble Sorted: ");
      printArray(tempArr, n);
      break;
    case 2:
      // Call Selection Sort
      selectionSort(tempArr, n);
      printf("Selection Sorted: ");
      printArray(tempArr, n);
      break;
    case 3:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice!\n");
    }
  } while (choice != 3);

  // Return 0 for success
  return 0;
}
