/*
 * ============================================================
 * SORTING 02: SELECTION SORT
 * ============================================================
 * Topic: Sorting (Simplified)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * Selection Sort logic is very intuitive: it splits the array 
 * into two parts: sorted and unsorted. It repeatedly finds the 
 * smallest element from the unsorted part and swaps it with the 
 * first element of the unsorted part, thus "selecting" the 
 * correct element for each position.
 *
 * ALGORITHM:
 * 1. START
 * 2. Loop i from 0 to n-2 (target position to fill).
 * 3. Assume arr[i] is the minimum (min_idx = i).
 * 4. Loop j from i+1 to n-1 (find the actual minimum).
 *    a. IF arr[j] < arr[min_idx]:
 *       i. Update min_idx = j.
 * 5. Swap arr[i] with arr[min_idx].
 * 6. Repeat until the entire array is sorted.
 * 7. STOP
 * ============================================================
 */

#include <stdio.h>

void printArray(int arr[], int size) {
    printf("  [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

/* 
 * The Selection Sort function.
 * Steps:
 * 1. Find the smallest element in the unsorted part.
 * 2. Swap it with the current first element of that part.
 */
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        /* Find the minimum element in unsorted array */
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        /* Swap the found minimum element with the first element */
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;

        printf("\nPass %d: (found minimum %d at index %d)\n", i+1, arr[i], min_idx);
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("=== SELECTION SORT ===\n\n");
    printf("Original array:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("\nSorted array:\n");
    printArray(arr, n);

    return 0;
}

/*
 * ============================================================
 * STUDENT NOTE:
 * ============================================================
 * Selection sort always makes O(n^2) comparisons, regardless 
 * of whether the array is already sorted or not.
 * However, it performs fewer Swaps compared to Bubble Sort.
 * ============================================================
 * 
 * EXPECTED OUTPUT:
 * === SELECTION SORT ===
 *
 * Original array:
 *   [ 29 10 14 37 13 ]
 *
 * Pass 1: (found minimum 10 at index 1)
 *   [ 10 29 14 37 13 ]
 * ...
 * Sorted array:
 *   [ 10 13 14 29 37 ]
 * ============================================================
 */
