// Include standard input/output library for printf and scanf
#include <stdio.h>
// Include stdlib for memory allocation functions like malloc and free
#include <stdlib.h>

// Main function entry using integer return type
int main() {
  // Declare two integer pointers: ptr for the start of memory, temp for
  // traversing
  int *ptr, *temp;
  // Declare an integer variable n to store the number of elements
  int n;
  // Prompt the user to enter how many integers they want to store
  printf("\nEnter the number of data: ");
  // Read the number from input and store it in variable n
  scanf("%d", &n);
  // Allocate memory for n integers and cast the void pointer to int pointer
  ptr = (int *)malloc(n * sizeof(int));
  // Set temp to point to the start of the allocated memory block
  temp = ptr;
  // Loop n times to read data into the allocated memory
  for (int i = 0; i < n; i++) {
    // Prompt for each data item
    printf("\nEnter the data : ");
    // Read an integer and store it at the memory location pointed to by temp
    scanf("%d", temp);
    // Move the temp pointer to the next integer position/address
    temp++;
  }
  // Reset temp to point back to the start of the memory block
  temp = ptr;
  // Loop n times to print the stored data
  for (int i = 0; i < n; i++) {
    // Print the integer value at the address pointed to by temp
    printf("\n%d ", *temp);
    // Move the temp pointer to the next integer position
    temp++;
  }
  // Free the allocated memory to prevent memory leaks
  free(ptr);
  // Return 0 to indicate successful program termination
  return 0;
}