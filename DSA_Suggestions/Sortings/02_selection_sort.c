/*
 * ============================================================
 * SORTING 02: SELECTION SORT
 * ============================================================
 * Topic: Sorting Algorithms
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS SELECTION SORT?
 * Selection Sort divides the array into two parts:
 *   - Sorted part:   on the LEFT (starts empty)
 *   - Unsorted part: on the RIGHT (starts as full array)
 *
 * In each pass:
 *   1. FIND the MINIMUM element in the unsorted part.
 *   2. SWAP it with the first element of the unsorted part.
 *   3. The sorted part grows by 1.
 *
 * Example:
 *   [29, 10, 14, 37, 13]
 *
 *   Pass 1: Min in [29,10,14,37,13] = 10 at index 1.
 *           Swap 29 and 10 -> [10, 29, 14, 37, 13]
 *
 *   Pass 2: Min in [29,14,37,13] = 13 at index 4.
 *           Swap 29 and 13 -> [10, 13, 14, 37, 29]
 *
 *   ... and so on.
 * ============================================================
 */

#include <stdio.h>

#define SIZE 8

/* ---- FUNCTION: swap ---- */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* ---- FUNCTION: displayArray ---- */
void displayArray(int arr[], int n, int sortedUpTo) {
    int i;
    printf("  [ ");
    for (i = 0; i < n; i++) {
        if (i < sortedUpTo) {
            printf("*%d*", arr[i]);  /* Mark sorted elements with asterisks */
        } else {
            printf("%d", arr[i]);
        }
        if (i < n - 1) printf(", ");
    }
    printf(" ]  (* = sorted)\n");
}

/* ---- FUNCTION: selectionSort ----
 * Outer loop i: position to fill (0 to n-2)
 * Inner loop j: find minimum in arr[i..n-1]
 *
 * For each position i, find the smallest remaining element
 * and put it at position i.
 */
void selectionSort(int arr[], int n) {
    int i, j, minIdx;

    printf("\n--- SELECTION SORT STEP-BY-STEP ---\n");

    for (i = 0; i < n - 1; i++) {
        /* Find the minimum element in arr[i..n-1] */
        minIdx = i;   /* Assume first element of unsorted part is minimum */

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;   /* Found a new minimum, update minIdx */
            }
        }

        /* Swap the found minimum with arr[i] */
        if (minIdx != i) {
            printf("  Pass %d: Min=%d at index %d, swap with index %d (%d)\n",
                   i + 1, arr[minIdx], minIdx, i, arr[i]);
            swap(&arr[i], &arr[minIdx]);
        } else {
            printf("  Pass %d: Min=%d already at index %d, no swap needed.\n",
                   i + 1, arr[i], i);
        }

        displayArray(arr, n, i + 1);
    }
}

/* ---- MAIN ---- */
int main() {
    int arr[] = {29, 10, 14, 37, 13, 52, 8, 41};
    int n = SIZE;

    printf("=== SELECTION SORT ===\n\n");

    printf("Original array:\n");
    displayArray(arr, n, 0);

    selectionSort(arr, n);

    printf("\nFinal sorted array:\n");
    displayArray(arr, n, n);

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === SELECTION SORT ===
 *
 * Original array:
 *   [ 29, 10, 14, 37, 13, 52, 8, 41 ]  (* = sorted)
 *
 * --- SELECTION SORT STEP-BY-STEP ---
 *   Pass 1: Min=8 at index 6, swap with index 0 (29)
 *   [ *8*, 10, 14, 37, 13, 52, 29, 41 ]  (* = sorted)
 *
 *   Pass 2: Min=10 at index 1, swap with index 1 (10)... No swap needed
 *   [*8*, *10*, 14, 37, 13, 52, 29, 41 ]  (* = sorted)
 *
 *   Pass 3: Min=13 at index 4, swap with index 2 (14)
 *   [ *8*, *10*, *13*, 37, 14, 52, 29, 41 ]  (* = sorted)
 *
 *   ... and so on
 *
 * Final sorted array:
 *   [ *8*, *10*, *13*, *14*, *29*, *37*, *41*, *52* ]
 *
 * ============================================================
 * HOW SELECTION SORT WORKS:
 * ============================================================
 *
 * Imagine selecting the smallest card from a hand:
 *   - Look through all your cards, find the smallest.
 *   - Place it at the leftmost position.
 *   - Now find the smallest among remaining cards.
 *   - Place it second from left.
 *   - Repeat.
 *
 * ALGORITHM (Pseudocode):
 *   FOR i = 0 to n-2:
 *       minIdx = i
 *       FOR j = i+1 to n-1:
 *           IF arr[j] < arr[minIdx]:
 *               minIdx = j
 *       SWAP arr[i] and arr[minIdx]
 *
 * WHY n-1 in outer loop?
 *   After n-1 selections, the nth element is automatically
 *   the largest and is already in the correct position.
 *
 * COMPARISON vs BUBBLE SORT:
 *   Both are O(n^2), but SELECTION SORT does fewer SWAPS:
 *   Bubble Sort: up to O(n^2) swaps
 *   Selection Sort: exactly n-1 swaps (one per pass)
 *   This makes Selection Sort better when writing is expensive.
 *
 * TIME COMPLEXITY:
 *   Best Case:  O(n^2) — always scans full unsorted portion
 *   Worst Case: O(n^2)
 *   Average:    O(n^2)
 *   (No early exit possible in selection sort)
 *
 * SPACE COMPLEXITY: O(1) — in-place sorting
 *
 * STABILITY: NO — equal elements may change relative order
 * ============================================================
 */
