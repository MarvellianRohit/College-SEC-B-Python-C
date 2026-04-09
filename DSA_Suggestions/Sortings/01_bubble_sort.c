/*
 * ============================================================
 * SORTING 01: BUBBLE SORT
 * ============================================================
 * Topic: Sorting (Simplified)
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS BUBBLE SORT?
 * It is a simple sorting algorithm that works by repeatedly 
 * swapping adjacent elements if they are in the wrong order.
 *
 * In each pass, the largest element "bubbles up" to the end.
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
 */
