/*
Question: Write a C program that:
• Takes the number of integers from the user.
• Uses calloc() / malloc to allocate memory for them.
• Reads all numbers, calculates, and prints their sum and average.
*/

// Include standard input/output library
#include <stdio.h>
// Include stdlib.h for malloc/free
#include <stdlib.h>

// Main function
int main() {
  // Declare integer variable for number of elements n, loop counter i, and
  // pointer arr
  int n, i, *arr;
  // Declare and initialize sum to 0
  int sum = 0;
  // Declare float variable for average
  float avg;

  // Prompt user for n
  printf("Enter number of elements: ");
  // Read n
  scanf("%d", &n);

  // Allocate memory for n integers using malloc
  // n * sizeof(int) calculates total bytes needed
  arr = (int *)malloc(n * sizeof(int));

  // Check if memory was successfully allocated
  if (arr == NULL) {
    // Print error if failed
    printf("Memory allocation failed!\n");
    // Exit program
    return 1;
  }

  // Prompt user to enter elements
  printf("Enter %d integers:\n", n);
  // Loop n times to read inputs
  for (i = 0; i < n; i++) {
    // Read integer into allocated memory at index i
    scanf("%d", &arr[i]);
    // Add current element to sum
    sum += arr[i];
  }

  // Calculate average (cast sum to float for decimal precision)
  avg = (float)sum / n;

  // Print the Sum
  printf("Sum = %d\n", sum);
  // Print the Average formatted to 2 decimal places
  printf("Average = %.2f\n", avg);

  // Free the allocated memory
  free(arr);

  // Return 0 for success
  return 0;
}
