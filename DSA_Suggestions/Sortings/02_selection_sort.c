/*
 * ============================================================
 * SORTING 02: SELECTION SORT
 * ============================================================
 * Topic: Sorting (Simplified)
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS SELECTION SORT?
 * It works by repeatedly finding the MINIMUM element from 
 * the unsorted part and putting it at the beginning.
 *
 * Imagine looking through a pile of cards and picking the 
 * smallest one to put in your hand.
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
 */
