/*
Question: Write a C program that:
• Uses malloc() to allocate memory for n integers.
• Takes input for all elements.
• Then uses realloc() to increase the size to n + m and takes m more elements.
• Displays all the elements after resizing.
*/

// Include standard input/output library
#include <stdio.h>
// Include stdlib.h for dynamic memory functions
#include <stdlib.h>

// Main function
int main() {
  // Declare variables: n (initial size), m (new size), i (index), arr (pointer)
  int n, m, i, *arr;

  // Prompt for initial size n
  printf("Enter initial number of elements (n): ");
  // Read n
  scanf("%d", &n);

  // Allocate memory for n integers
  arr = (int *)malloc(n * sizeof(int));

  // Check memory allocation
  if (arr == NULL) {
    // Print error and exit
    printf("Memory allocation failed!\n");
    return 1;
  }

  // Prompt for initial elements
  printf("Enter %d integers:\n", n);
  // Loop to read n integers
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Prompt for additional size m
  printf("Enter number of new elements to add (m): ");
  // Read m
  scanf("%d", &m);

  // Reallocate memory to hold (n + m) integers
  // realloc preserves existing content
  arr = (int *)realloc(arr, (n + m) * sizeof(int));

  // Check if reallocation succeeded
  if (arr == NULL) {
    // Print error and exit
    printf("Memory reallocation failed!\n");
    return 1;
  }

  // Prompt for m new elements
  printf("Enter %d more integers:\n", m);
  // Loop from n to n + m to read new elements
  for (i = n; i < n + m; i++) {
    scanf("%d", &arr[i]);
  }

  // Display all elements after info
  printf("\nAll elements after resizing:\n");
  // Loop through all (n + m) elements
  for (i = 0; i < n + m; i++) {
    // Print element
    printf("%d ", arr[i]);
  }
  // Print newline
  printf("\n");

  // Free the memory
  free(arr);

  // Return 0 for success
  return 0;
}
