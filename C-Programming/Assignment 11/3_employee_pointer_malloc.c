/*
Question: Write a C program that:
• Uses a pointer to a structure.
• Dynamically allocates memory for one Employee structure with members:
• id (int)
• name (string)
• salary (float)
• Takes input and displays employee details using the pointer.
*/

// Include standard input/output library
#include <stdio.h>
// Include stdlib.h for dynamic memory allocation
#include <stdlib.h>

// Define Employee structure
struct Employee {
  // Integer for ID
  int id;
  // String for Name
  char name[50];
  // Float for Salary
  float salary;
};

// Main function
int main() {
  // Declare a pointer to struct Employee
  struct Employee *ptr;

  // Allocate memory for exactly one Employee structure
  // sizeof(struct Employee) calculates required bytes
  ptr = (struct Employee *)malloc(sizeof(struct Employee));

  // Check if memory allocation failed
  if (ptr == NULL) {
    // Print error message
    printf("Memory allocation failed!\n");
    // Exit with error
    return 1;
  }

  // Prompt for Employee Details
  printf("Enter Employee Details:\n");

  // Prompt for ID
  printf("ID: ");
  // Read ID using pointer access (-> operator)
  scanf("%d", &ptr->id);

  // Prompt for Name
  printf("Name: ");
  // Read Name using pointer access
  scanf("%s", ptr->name);

  // Prompt for Salary
  printf("Salary: ");
  // Read Salary using pointer access
  scanf("%f", &ptr->salary);

  // Display Output Header
  printf("\n--- Employee Details ---\n");
  // Print ID
  printf("ID: %d\n", ptr->id);
  // Print Name
  printf("Name: %s\n", ptr->name);
  // Print Salary
  printf("Salary: %.2f\n", ptr->salary);

  // Free the allocated memory
  free(ptr);

  // Return 0 for success
  return 0;
}
