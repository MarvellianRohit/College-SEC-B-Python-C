#include <stdio.h> // Include standard input-output library

/**
 * Program to search a number from 10 numbers using linear search
 * and show the occurrence of the search item.
 */
int main() {
  int arr[10];    // Declare an integer array to hold 10 elements
  int searchItem; // Variable to store the item being searched for
  int i;          // Loop counter
  int count = 0;  // Counter to keep track of number of occurrences found

  printf("Enter 10 numbers:\n");   // Prompt user for 10 integers
  for (i = 0; i < 10; i++) {       // Loop through each array index from 0 to 9
    printf("Element %d: ", i + 1); // Print element number (1-based)
    scanf("%d", &arr[i]);          // Store user input in array at index i
  }

  printf(
      "\nEnter the number to search: "); // Prompt for the number to search for
  scanf("%d", &searchItem);              // Input the number to search

  printf("Searching for %d...\n",
         searchItem); // Visual feedback for search start

  // Linear Search Logic for all occurrences
  for (i = 0; i < 10; i++) {    // Traverse the array from start to end
    if (arr[i] == searchItem) { // Check if current element matches searchItem
      printf("Found at position %d (index %d)\n", i + 1,
             i); // Print position if match
      count++;   // Increment occurrence counter
    }
  }

  if (count > 0) { // If at least one occurrence was found
    printf("\nTotal occurrences of %d: %d\n", searchItem,
           count); // Print total count
  } else {         // If the counter is still zero
    printf("Number %d not found in the array.\n",
           searchItem); // Inform user it wasn't found
  }

  return 0; // Successful program termination
}
