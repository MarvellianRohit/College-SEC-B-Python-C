/*
Question: Remove Duplicates: This program takes an array and creates a new one
containing only the unique elements.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  int n, i, j, k = 0, isDuplicate;

  // Input array size
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  // Declare original and unique arrays
  int arr[n], uniqueArr[n];

  // Input array elements
  printf("Enter %d integers:\n", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Logic to find unique elements
  for (i = 0; i < n; i++) {
    isDuplicate = 0;
    // Check if current element already exists in uniqueArr
    for (j = 0; j < k; j++) {
      if (arr[i] == uniqueArr[j]) {
        isDuplicate = 1;
        break;
      }
    }

    // If not a duplicate, add to uniqueArr
    if (!isDuplicate) {
      uniqueArr[k] = arr[i];
      k++; // Increment size of unique array
    }
  }

  // Print unique elements
  printf("Array with unique elements:\n");
  for (i = 0; i < k; i++) {
    printf("%d ", uniqueArr[i]);
  }
  printf("\n");

  // Return 0 for success
  return 0;
}
