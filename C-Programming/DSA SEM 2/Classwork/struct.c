// Include standard input/output library
#include <stdio.h>
// Include standard library for memory allocation
#include <stdlib.h>

// Define a structure 'Student' containing a roll number and name
struct Student {
  // Integer for roll number
  int roll_no;
  // Character array for name
  char name[20];
};

// Main function entry point
int main() {
  // Declare pointers for struct Student
  struct Student *ptr, *temp;
  // Variable to store the number of student records
  int n;
  // Prompt user for the number of records
  printf("\nEnter the number of data: ");
  // Read the number of records
  scanf("%d", &n);
  // Allocate memory dynamically for 'n' Student structures
  ptr = (struct Student *)malloc(n * sizeof(struct Student));
  // Initialize 'temp' to point to the start of the allocated memory
  temp = ptr;
  // Loop to input data for each student
  for (int i = 0; i < n; i++) {
    // Prompt for roll number
    printf("\nEnter the Roll:  : ");
    // Read roll number into the structure pointed to by temp
    scanf("%d", &temp->roll_no);
    // Prompt for name
    printf("\nEnter the Name:  : ");
    // Read name into the structure pointed to by temp
    scanf("%s", temp->name);
    // Move 'temp' pointer to the next struct in the allocated block
    temp++;
  }
  // Reset 'temp' to point to the start of the memory block for printing
  temp = ptr;
  // Loop to display the data for each student
  for (int i = 0; i < n; i++) {
    // Print roll number
    printf("\nRoll No: %d ", temp->roll_no);
    // Print name
    printf("\nName: %s ", temp->name);
    // Move 'temp' pointer to the next struct
    temp++;
  }
  // Free the dynamically allocated memory
  free(ptr);
  // Return 0 for successful execution
  return 0;
}