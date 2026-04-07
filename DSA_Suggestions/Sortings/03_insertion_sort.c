/*
 * ============================================================
 * SORTING 03: INSERTION SORT
 * ============================================================
 * Topic: Sorting Algorithms
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS INSERTION SORT?
 * Insertion Sort builds a sorted array ONE ELEMENT AT A TIME.
 *
 * Think of sorting playing cards in your hand:
 * You pick up one card at a time and INSERT it into the
 * correct position among the already-sorted cards in your hand.
 *
 * At each step:
 *   - Pick the NEXT element (called 'key')
 *   - Compare it with elements to its LEFT (already sorted)
 *   - SHIFT all larger elements one position to the right
 *   - INSERT key in the correct position
 *
 * Example:
 *   [5, 2, 4, 6, 1, 3]
 *   key=2: compare with 5, 5>2 so shift 5 right -> insert 2 -> [2,5,4,6,1,3]
 *   key=4: compare with 5, 5>4 so shift 5 right -> 4>2 stop -> insert 4 -> [2,4,5,6,1,3]
 *   ...
 * ============================================================
 */

#include <stdio.h>

#define SIZE 8

/* ---- FUNCTION: displayArray ---- */
void displayArray(int arr[], int n) {
    int i;
    printf("  [ ");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf(" ]\n");
}

/* ---- FUNCTION: insertionSort ----
 * Outer loop i: picks each element starting from index 1
 *               (index 0 is considered "sorted" by itself)
 * Inner loop j: shifts elements that are greater than 'key'
 *               one position to the right
 */
void insertionSort(int arr[], int n) {
    int i, j;
    int key;   /* The element we're currently trying to insert */

    printf("\n--- INSERTION SORT STEP-BY-STEP ---\n");

    for (i = 1; i < n; i++) {
        key = arr[i];   /* Pick the next element to insert */
        j = i - 1;      /* Start comparing from element just left of key */

        printf("  Step %d: key=%d, shifting elements > %d to right\n", i, key, key);

        /* Shift all elements greater than key one position to the right */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];   /* Move arr[j] one step right */
            j--;                    /* Move j left */
        }

        /* j+1 is now the correct position for key */
        arr[j + 1] = key;   /* Insert key at correct position */

        displayArray(arr, n);
    }
}

/* ---- MAIN ---- */
int main() {
    int arr[] = {5, 2, 4, 6, 1, 3, 8, 7};
    int n = SIZE;

    printf("=== INSERTION SORT ===\n\n");

    printf("Original array:\n");
    displayArray(arr, n);

    insertionSort(arr, n);

    printf("\nSorted array:\n");
    displayArray(arr, n);

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === INSERTION SORT ===
 *
 * Original array:
 *   [ 5, 2, 4, 6, 1, 3, 8, 7 ]
 *
 * --- INSERTION SORT STEP-BY-STEP ---
 *   Step 1: key=2, shifting elements > 2 to right
 *   [ 2, 5, 4, 6, 1, 3, 8, 7 ]
 *
 *   Step 2: key=4, shifting elements > 4 to right
 *   [ 2, 4, 5, 6, 1, 3, 8, 7 ]
 *
 *   Step 3: key=6, shifting elements > 6 to right
 *   [ 2, 4, 5, 6, 1, 3, 8, 7 ]  (6 already in place)
 *
 *   Step 4: key=1, shifting elements > 1 to right
 *   [ 1, 2, 4, 5, 6, 3, 8, 7 ]
 *
 *   Step 5: key=3, shifting elements > 3 to right
 *   [ 1, 2, 3, 4, 5, 6, 8, 7 ]
 *
 *   Step 6: key=8, shifting elements > 8 to right
 *   [ 1, 2, 3, 4, 5, 6, 8, 7 ]  (8 already in place)
 *
 *   Step 7: key=7, shifting elements > 7 to right
 *   [ 1, 2, 3, 4, 5, 6, 7, 8 ]
 *
 * Sorted array:
 *   [ 1, 2, 3, 4, 5, 6, 7, 8 ]
 *
 * ============================================================
 * HOW INSERTION SORT WORKS:
 * ============================================================
 *
 * Playing card analogy:
 *   - Sorted hand (left side) grows one card at a time.
 *   - Pick up next card from the table (key).
 *   - Slide it into the correct position in your hand.
 *
 * ALGORITHM (Pseudocode):
 *   FOR i = 1 to n-1:
 *       key = arr[i]
 *       j = i - 1
 *       WHILE j >= 0 AND arr[j] > key:
 *           arr[j+1] = arr[j]   // shift element right
 *           j = j - 1
 *       arr[j+1] = key          // insert at correct spot
 *
 * CRITICAL STEP: We SHIFT (not swap) elements.
 *   Shifting: arr[j+1] = arr[j]  — copy, no temp variable needed
 *   This is faster than swapping (one write vs three for swap).
 *
 * WHY IS IT EFFICIENT FOR NEARLY SORTED DATA?
 *   If array is nearly sorted, the inner WHILE loop runs very few
 *   iterations — elements are already close to their correct positions.
 *   In the BEST CASE (already sorted), inner loop never runs -> O(n).
 *
 * TIME COMPLEXITY:
 *   Best Case:  O(n)   — array already sorted
 *   Worst Case: O(n^2) — array reverse sorted
 *   Average:    O(n^2)
 *
 * SPACE COMPLEXITY: O(1) — in-place
 *
 * STABILITY: YES — equal elements never pass each other (arr[j] > key, not >=)
 *
 * REAL-WORLD USE:
 *   Used in Timsort (Python and Java's built-in sort!) for small sub-arrays.
 *   Excellent for small n or nearly-sorted data.
 * ============================================================
 */
