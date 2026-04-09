/*
 * ============================================================
 * SORTING 03: INSERTION SORT
 * ============================================================
 * Topic: Sorting (Simplified)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * Insertion Sort works by building a sorted array one element at 
 * a time. It takes each element from the unsorted part and 
 * "inserts" it into its correct position in the sorted part by 
 * shifting larger elements one position to the right. 
 * It is similar to how you sort playing cards in your hand.
 *
 * ALGORITHM:
 * 1. START
 * 2. Loop i from 1 to n-1 (the element to be inserted).
 * 3. Store the current element: key = arr[i].
 * 4. Set j = i - 1.
 * 5. WHILE j >= 0 AND arr[j] > key:
 *    a. Shift arr[j] to the right: arr[j+1] = arr[j].
 *    b. Decrement j.
 * 6. Place the key at its correct position: arr[j+1] = key.
 * 7. Repeat for all elements.
 * 8. STOP
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
 * The Insertion Sort function.
 * Steps:
 * 1. Take an element (the 'key').
 * 2. Compare it with elements before it (to its left).
 * 3. Shift elements to the right until you find the right spot.
 * 4. Insert the 'key' there.
 */
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];   /* The card we want to insert */
        int j = i - 1;

        /* Move elements of arr[0..i-1] that are greater than key
           to one position ahead of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;   /* Put the key in its right place */

        printf("\nPass %d: (Inserted %d into its sorted position)\n", i, key);
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("=== INSERTION SORT ===\n\n");
    printf("Original array:\n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("\nFinal Sorted array:\n");
    printArray(arr, n);

    return 0;
}

/*
 * ============================================================
 * STUDENT NOTE:
 * ============================================================
 * Insertion Sort is very efficient for small datasets or 
 * arrays that are already "mostly sorted". 
 *
 * Time Complexity: O(n^2) in the worst case, but O(n) in 
 * the best case (when it's already sorted).
 * ============================================================
 * 
 * EXPECTED OUTPUT:
 * === INSERTION SORT ===
 *
 * Original array:
 *   [ 12 11 13 5 6 ]
 *
 * Pass 1: (Inserted 11 into its sorted position)
 *   [ 11 12 13 5 6 ]
 * ...
 * Final Sorted array:
 *   [ 5 6 11 12 13 ]
 * ============================================================
 */
