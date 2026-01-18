/*
Question: Merge Two Arrays
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Declare variables
  int n1, n2, n3, i, k;

  // Input size and elements of first array
  printf("Enter size of first array: ");
  scanf("%d", &n1);
  int arr1[n1];
  printf("Enter elements of first array:\n");
  for (i = 0; i < n1; i++) {
    scanf("%d", &arr1[i]);
  }

  // Input size and elements of second array
  printf("Enter size of second array: ");
  scanf("%d", &n2);
  int arr2[n2];
  printf("Enter elements of second array:\n");
  for (i = 0; i < n2; i++) {
    scanf("%d", &arr2[i]);
  }

  // Size of merged array
  n3 = n1 + n2;
  int arr3[n3];

  // Copy elements of first array to merged array
  for (i = 0; i < n1; i++) {
    arr3[i] = arr1[i];
  }

  // Copy elements of second array to merged array
  // Continue from index n1
  for (i = 0; i < n2; i++) {
    arr3[n1 + i] = arr2[i];
  }

  // Print merged array
  printf("Merged Array:\n");
  for (i = 0; i < n3; i++) {
    printf("%d ", arr3[i]);
  }
  printf("\n");

  // Return 0 for success
  return 0;
}
