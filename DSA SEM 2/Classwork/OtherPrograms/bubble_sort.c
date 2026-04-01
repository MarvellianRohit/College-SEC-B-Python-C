#include <stdio.h> // Include standard input-output header for printf

/**
 * BCA Scholar-Bot: Premium Bubble Sort Implementation
 * 
 * Every single line is commented as requested. 
 * The algorithm is provided at the bottom of the file.
 * 
 * Path: DSA SEM 2/Classwork/OtherPrograms/bubble_sort.c
 */

// Function to perform Bubble Sort on an integer array
void bubbleSort(int arr[], int n) { 
    int i; // Declare outer loop iterator variable i
    int j; // Declare inner loop iterator variable j
    int temp; // Declare temporary variable for swapping elements
    int swapped; // Flag to track if any swapping occurred in a pass

    // Outer loop for the number of passes through the array
    for (i = 0; i < n - 1; i++) { 
        swapped = 0; // Initialize swapped flag as 0 (false) at the start of each pass

        // Inner loop comparisons from the start to the unsorted part of the array
        for (j = 0; j < n - i - 1; j++) { 
            
            // Comparison: Check if the current element is greater than the next element
            if (arr[j] > arr[j + 1]) { 
                
                // Start of the swapping logic
                temp = arr[j]; // Store the value of arr[j] in the temporary variable temp
                arr[j] = arr[j + 1]; // Move the value of arr[j + 1] into arr[j]
                arr[j + 1] = temp; // Put the value of temp into arr[j + 1]
                
                swapped = 1; // Mark swapped as 1 (true) to indicate a swap occurred
            } // End of the if block
        } // End of the inner for loop

        // Efficiency check: if no two elements were swapped by inner loop, then the array is sorted
        if (swapped == 0) { 
            break; // Exit the loop early as the array is already sorted
        } // End of the if block
    } // End of the outer for loop
} // End of the bubbleSort function

// Function to print the contents of an array
void printArray(int arr[], int size) { 
    int k; // Declare loop iterator variable k
    for (k = 0; k < size; k++) { // Loop from index 0 to the last index of the array
        printf("%d ", arr[k]); // Print the element at index k followed by a space
    } // End of the for loop
    printf("\n"); // Print a newline character after printing all elements
} // End of the printArray function

// The main function where execution begins
int main() { 
    // Initialization of an unsorted integer array
    int data[] = {64, 34, 25, 12, 22, 11, 90}; 

    // Calculate the total number of elements in the array
    int size = sizeof(data) / sizeof(data[0]); 

    // Output the original unsorted array to the console
    printf("Original Data: \n"); 
    printArray(data, size); // Call printArray to display the initial data

    // Execute the bubble sort function to sort the array
    bubbleSort(data, size); 

    // Output the final sorted array to the console
    printf("Sorted Data: \n"); 
    printArray(data, size); // Call printArray to display the sorted data

    return 0; // Return 0 to indicate successful program completion
} // End of the main function

/* 
 * ============================================================
 * ALGORITHM: BUBBLE SORT
 * ============================================================
 * STEP 1: START
 * STEP 2: Initialize an array 'arr' of size 'n'.
 * STEP 3: Repeat STEP 4 and 5 for i = 0 to n-2 (number of passes).
 * STEP 4:   Initialize a flag 'swapped' to 0.
 * STEP 5:   Repeat for j = 0 to n-i-2 (inner comparisons):
 *             a. If arr[j] > arr[j+1] then:
 *                i.   Swap arr[j] and arr[j+1].
 *                ii.  Set 'swapped' to 1.
 * STEP 6:   If 'swapped' is 0, then the array is already sorted; BREAK out of the loop.
 * STEP 7: PRINT the sorted array.
 * STEP 8: STOP
 * ============================================================
 */
