#include <stdio.h> // Include standard input-output library for printf and scanf

/**
 * Program to search a number from 10 distinct numbers using linear search.
 */
int main() {
  int arr[10];    // Declare an integer array of size 10 to store numbers
  int searchItem; // Variable to store the number to be searched
  int i;          // Loop counter variable
  int found =
      0; // Flag variable to track if item is found (0 = False, 1 = True)

  printf("Enter 10 distinct numbers:\n"); // Prompt the user to enter 10
                                          // distinct numbers
  for (i = 0; i < 10; i++) {              // Start a loop that runs from 0 to 9
    printf("Element %d: ", i + 1); // Display current element number (1-based)
    scanf("%d", &arr[i]); // Read an integer from user and store it in array
  }

  printf("\nEnter the number to search: "); // Prompt for the search target
  scanf("%d", &searchItem); // Read the target number from the user

  // Linear Search Logic: Check each element one by one
  for (i = 0; i < 10; i++) {    // Iterate through the entire array
    if (arr[i] == searchItem) { // Compare current element with searchItem
      // If match found, print position and index
      printf("Number %d found at position %d (index %d).\n", searchItem, i + 1,
             i);
      found = 1; // Set found flag to 1 (True)
      break;     // Exit the loop early since numbers are distinct
    }
  }

  if (!found) { // If the found flag remains 0 after the loop
    printf("Number %d not found in the array.\n",
           searchItem); // Inform user item wasn't found
  }

  return 0; // Return 0 to indicate successful program execution
}
