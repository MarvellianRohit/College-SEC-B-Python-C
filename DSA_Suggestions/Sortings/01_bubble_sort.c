/*
 * ============================================================
 * SORTING 01: BUBBLE SORT
 * ============================================================
 * Topic: Sorting Algorithms
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS BUBBLE SORT?
 * Bubble Sort repeatedly steps through the array, compares
 * adjacent (side-by-side) elements, and SWAPS them if they
 * are in the wrong order (larger one comes first).
 *
 * After each PASS, the LARGEST unsorted element "bubbles up"
 * to its correct position at the right end.
 *
 * Like bubbles in water rising to the surface!
 *
 * Example:
 *   Array: [64, 25, 12, 22, 11]
 *
 *   Pass 1: compare (64,25) -> swap -> compare (64,12) -> swap
 *           -> compare (64,22) -> swap -> compare (64,11) -> swap
 *           Result: [25, 12, 22, 11, 64]  (64 is at correct position)
 *
 *   Pass 2: 25 bubbles up
 *   ... and so on until fully sorted.
 * ============================================================
 */

#include <stdio.h>

#define SIZE 8   /* Number of elements in array */

/* ---- FUNCTION: swap ----
 * Swaps two integers using a temporary variable.
 * We use pointers (*a, *b) to modify the actual values.
 */
void swap(int *a, int *b) {
    int temp = *a;   /* Save value of a in temp */
    *a = *b;         /* Copy b's value into a */
    *b = temp;       /* Copy saved value (a's original) into b */
}

/* ---- FUNCTION: displayArray ----
 * Prints all elements of the array in a line.
 */
void displayArray(int arr[], int n) {
    int i;
    printf("  [ ");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf(" ]\n");
}

/* ---- FUNCTION: bubbleSort ----
 * Sorts array arr[] of size n using Bubble Sort.
 *
 * OUTER LOOP (i): Runs n-1 passes (n-1 elements need to settle)
 * INNER LOOP (j): Compares adjacent pairs in unsorted portion
 *
 * Optimization: if no swap happened in a pass, array is sorted.
 * We use a 'swapped' flag to detect this early.
 */
void bubbleSort(int arr[], int n) {
    int i, j, swapped;

    printf("\n--- BUBBLE SORT STEP-BY-STEP ---\n");

    for (i = 0; i < n - 1; i++) {    /* Outer loop: n-1 passes */
        swapped = 0;                   /* Reset swap flag for this pass */

        printf("  Pass %d: ", i + 1);

        for (j = 0; j < n - 1 - i; j++) {   /* Inner loop: shrinks each pass */
            /* Compare adjacent elements */
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);  /* Swap if out of order */
                swapped = 1;                  /* Mark that a swap happened */
            }
        }

        displayArray(arr, n);

        /* After pass i, arr[n-1-i] to arr[n-1] are sorted */
        printf("           (Element %d is now in its final position)\n", arr[n - 1 - i]);

        /* Early exit: if no swaps in this pass, already sorted */
        if (swapped == 0) {
            printf("  No swaps in this pass! Array is sorted early.\n");
            break;
        }
    }
}

/* ---- MAIN ---- */
int main() {
    int arr[] = {64, 25, 12, 22, 11, 45, 8, 33};
    int n = SIZE;

    printf("=== BUBBLE SORT ===\n\n");

    printf("Original array:\n");
    displayArray(arr, n);

    bubbleSort(arr, n);

    printf("\nSorted array:\n");
    displayArray(arr, n);

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === BUBBLE SORT ===
 *
 * Original array:
 *   [ 64, 25, 12, 22, 11, 45, 8, 33 ]
 *
 * --- BUBBLE SORT STEP-BY-STEP ---
 *   Pass 1:   [ 25, 12, 22, 11, 45, 8, 33, 64 ]
 *              (Element 64 is now in its final position)
 *   Pass 2:   [ 12, 22, 11, 25, 8, 33, 45, 64 ]
 *              (Element 45 is now in its final position)
 *   Pass 3:   [ 12, 11, 22, 8, 25, 33, 45, 64 ]
 *              (Element 33 is now in its final position)
 *   Pass 4:   [ 11, 12, 8, 22, 25, 33, 45, 64 ]
 *              (Element 25 is now in its final position)
 *   Pass 5:   [ 11, 8, 12, 22, 25, 33, 45, 64 ]
 *              (Element 22 is now in its final position)
 *   Pass 6:   [ 8, 11, 12, 22, 25, 33, 45, 64 ]
 *              (Element 12 is now in its final position)
 *   Pass 7:   [ 8, 11, 12, 22, 25, 33, 45, 64 ]
 *   No swaps in this pass! Array is sorted early.
 *
 * Sorted array:
 *   [ 8, 11, 12, 22, 25, 33, 45, 64 ]
 *
 * ============================================================
 * HOW BUBBLE SORT WORKS:
 * ============================================================
 *
 * Imagine sorting people by height in a line:
 * You walk through the line comparing two neighbors at a time.
 * If the left person is taller, they swap.
 * After one full walk, the TALLEST person is at the end.
 * Repeat for smaller groups until everyone is sorted.
 *
 * PASS 1 walkthrough for [64, 25, 12, 22, 11]:
 *   Compare 64 and 25: 64 > 25, SWAP -> [25, 64, 12, 22, 11]
 *   Compare 64 and 12: 64 > 12, SWAP -> [25, 12, 64, 22, 11]
 *   Compare 64 and 22: 64 > 22, SWAP -> [25, 12, 22, 64, 11]
 *   Compare 64 and 11: 64 > 11, SWAP -> [25, 12, 22, 11, 64]
 *   64 has "bubbled" to the end!
 *
 * WHY n-1-i in inner loop?
 *   After each pass, the last i elements are already sorted.
 *   No need to check them again — saves comparisons.
 *
 * TIME COMPLEXITY:
 *   Best Case:  O(n)   — array already sorted (with swapped flag)
 *   Worst Case: O(n^2) — array is reverse sorted
 *   Average:    O(n^2)
 *
 * SPACE COMPLEXITY: O(1) — sorts in-place, no extra array needed
 *
 * STABILITY: YES — equal elements maintain their relative order
 *
 * WHEN TO USE:
 *   Small datasets or nearly-sorted data.
 *   NOT efficient for large datasets.
 * ============================================================
 */
