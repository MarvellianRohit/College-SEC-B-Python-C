/*
 * ============================================================
 * SORTING 01: BUBBLE SORT
 * ============================================================
 * Topic: Sorting (Simplified)
 * Language: C
 * Level: 1st Year BCA
 *
 * DETAILED EXPLANATION:
 * Bubble Sort is a simple sorting algorithm that repeatedly steps
 * through the list, compares adjacent elements and swaps them if
 * they are in the wrong order. The pass through the list is
 * repeated until the list is sorted. The largest elements
 * "bubble up" to their correct position at the end of the array.
 *
 * ALGORITHM:
 * 1. START
 * 2. Loop i from 0 to size-2 (Total passes).
 * 3. Loop j from 0 to size-i-2 (Comparisons in each pass).
 * 4. IF arr[j] > arr[j+1]:
 *    a. Swap arr[j] and arr[j+1].
 * 5. Repeat until the array is sorted.
 * 6. STOP
 * ============================================================
 */

#include <stdio.h>

/* Function to print an array */
void printArray(int arr[], int size) {
  printf("  [ ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("]\n");
}

/*
 * The Bubble Sort function.
 * It uses two loops:
 * 1. Outer loop: for each element in the array.
 * 2. Inner loop: for comparing neighbor elements.
 */
void bubbleSort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    printf("\nPass %d:\n", i + 1);

    for (int j = 0; j < size - i - 1; j++) {
      /* Compare neighbor elements */
      if (arr[j] > arr[j + 1]) {
        /* Swap them if they are in wrong order */
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;

        printf("  Swapped %d and %d\n", arr[j + 1], arr[j]);
      }
    }
    printArray(arr, size);
  }
}

int main() {
  int arr[] = {64, 34, 25, 12, 22};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("=== BUBBLE SORT ===\n\n");
  printf("Original array:\n");
  printArray(arr, n);

  bubbleSort(arr, n);

  printf("\nSorted array:\n");
  printArray(arr, n);

  return 0;
}

/*
 * ============================================================
 * STUDENT NOTE:
 * ============================================================
 * Outer loop (i): Runs 'n-1' times.
 * Inner loop (j): Compares neighbors. After each outer pass,
 * the largest unsorted number moves to its final position.
 *
 * Time Complexity: O(n^2) - because of the nested loops.
 * ============================================================
 *
 * EXPECTED OUTPUT:
 * === BUBBLE SORT ===
 *
 * Original array:
 *   [ 64 34 25 12 22 ]
 *
 * Pass 1:
 *   Swapped 64 and 34
 *   Swapped 64 and 25
 *   Swapped 64 and 12
 *   Swapped 64 and 22
 *   [ 34 25 12 22 64 ]
 *
 * Pass 2:
 *   Swapped 34 and 25
 *   Swapped 34 and 12
 *   Swapped 34 and 22
 *   [ 25 12 22 34 64 ]
 *
 * Pass 3:
 *   Swapped 25 and 12
 *   Swapped 25 and 22
 *   [ 12 22 25 34 64 ]
 *
 * Pass 4:
 *   [ 12 22 25 34 64 ]
 *
 * Sorted array:
 *   [ 12 22 25 34 64 ]
 * ============================================================
 */
