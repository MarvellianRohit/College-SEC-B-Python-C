#include <stdio.h> // Standard I/O header for input/output functions

/**
 * Program to search a number from 10 numbers using binary search.
 * Note: Binary search requires the array to be sorted.
 */
int main() {
  int arr[10];        // Array to store 10 numeric values
  int searchItem;     // Value to search for
  int i, j, temp;     // Loop counters and a temporary variable for sorting
  int low, high, mid; // Variables for tracking range boundaries and midpoint
  int found = 0;      // Boolean flag to indicate if search target is found

  printf("Enter 10 numbers:\n"); // Ask the user to input data
  for (i = 0; i < 10; i++) {     // Loop to read 10 numbers
    printf("Element %d: ", i + 1);
    scanf("%d", &arr[i]); // Read and store each number
  }

  // Binary search requires sorted data. Sorting the array using Bubble Sort
  // algorithm.
  for (i = 0; i < 9; i++) {       // Outer loop for passes
    for (j = 0; j < 9 - i; j++) { // Inner loop for comparisons in a pass
      if (arr[j] > arr[j + 1]) {  // If current element is greater than next
        temp = arr[j];            // Swap the elements
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  printf("\nSorted array (required for binary search):\n"); // Show sorted array
                                                            // status
  for (i = 0; i < 10; i++) { // Loop to print elements
    printf("%d ", arr[i]);   // Print each element separated by space
  }

  printf("\n\nEnter the number to search: "); // Get target value from user
  scanf("%d", &searchItem);                   // Input search item

  // Binary Search Logic: Divide and Conquer
  low = 0;  // Initialize search range at the start
  high = 9; // Initialize search range at the end

  while (low <= high) {     // Continue while the search range is valid
    mid = (low + high) / 2; // Calculate the middle index of the current range

    if (arr[mid] == searchItem) { // Check if middle element is the target
      printf("Number %d found at index %d in the sorted array.\n", searchItem,
             mid);
      found = 1;                        // Mark as found
      break;                            // Exit while loop
    } else if (arr[mid] < searchItem) { // If target is in the right half
      low = mid + 1;                    // Narrow range to the right portion
    } else {                            // If target is in the left half
      high = mid - 1;                   // Narrow range to the left portion
    }
  }

  if (!found) { // If the entire range was checked and target not found
    printf("Number %d not found in the array.\n",
           searchItem); // Inform the user
  }

  return 0; // Successful completion
}
