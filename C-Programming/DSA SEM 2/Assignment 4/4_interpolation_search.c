#include <stdio.h> // Standard I/O functions

/**
 * Program to search a number from 10 numbers using interpolation search.
 * Note: Interpolation search requires the array to be sorted and
 * works best for uniformly distributed values.
 */
int main() {
  int arr[10];        // Storage for 10 integer values
  int searchItem;     // Value to locate in the array
  int i, j, temp;     // Sorting and iteration helpers
  int low, high, pos; // Boundaries and estimated position variable
  int found = 0;      // Success flag

  printf("Enter 10 numbers:\n"); // Prompt input from user
  for (i = 0; i < 10; i++) {     // Loop to fill the array
    printf("Element %d: ", i + 1);
    scanf("%d", &arr[i]); // Accumulate numbers
  }

  // Interpolation search requires sorted data. Sorting using Bubble Sort.
  for (i = 0; i < 9; i++) {       // Passes through array
    for (j = 0; j < 9 - i; j++) { // Comparisons per pass
      if (arr[j] > arr[j + 1]) {  // Compare adjacent elements
        temp = arr[j];            // Swap if they are in wrong order
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  printf(
      "\nSorted array (required for interpolation search):\n"); // Display sort
                                                                // result
  for (i = 0; i < 10; i++) { // Print sorted elements
    printf("%d ", arr[i]);
  }

  printf("\n\nEnter the number to search: "); // Ask target for search
  scanf("%d", &searchItem);                   // Input search target

  // Interpolation Search Logic
  low = 0;  // Search range start
  high = 9; // Search range end

  // Continue searching while target is within boundaries of current range
  while (low <= high && searchItem >= arr[low] && searchItem <= arr[high]) {
    // Position Estimation Formula (similar to linear interpolation)
    if (low == high) {              // Handle single-element range case
      if (arr[low] == searchItem) { // Check if it's the target
        pos = low;                  // Position is low
      } else {                      // Target not found
        break;                      // Exit loop
      }
    } else {
      // Formula to estimate where target might be based on value distribution
      pos = low + (((double)(high - low) / (arr[high] - arr[low])) *
                   (searchItem - arr[low]));
    }

    if (arr[pos] == searchItem) { // If target is found at estimated position
      printf("Number %d found at index %d in the sorted array.\n", searchItem,
             pos);
      found = 1; // Set success flag
      break;     // Terminate search
    }

    if (arr[pos] < searchItem) { // If target is greater than estimated position
      low = pos + 1;             // Search in the upper part
    } else {                     // If target is smaller than estimated position
      high = pos - 1;            // Search in the lower part
    }
  }

  if (!found) { // If loop completes without finding target
    printf("Number %d not found in the array.\n",
           searchItem); // Not available in array
  }

  return 0; // Program end
}

/*
Output:
Enter 10 numbers:
Element 1: Element 2: Element 3: Element 4: Element 5: Element 6: Element 7: Element 8: Element 9: Element 10: 
Sorted array (required for interpolation search):
-104919616 -102116792 -102102688 -16 -1 0 1 1 1 1 

Enter the number to search: Number 1872899024 not found in the array.
*/
