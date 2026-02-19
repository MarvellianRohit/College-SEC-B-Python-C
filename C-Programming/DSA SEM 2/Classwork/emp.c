// Include the standard input/output library
#include <stdio.h>

// Define a structure named 'emp' to hold employee details
struct emp {
  // Integer variable to store employee code
  int emp_code;
  // Character array (string) to store employee name, max 20 chars
  char emp_name[20];
};

// Main function where the program execution begins
int main() {
  // Declare a variable 'e1' of type 'struct emp' and a pointer 'e2' to a
  // 'struct emp'
  struct emp e1, *e2;
  // Assign the address of e1 to pointer e2
  e2 = &e1;
  // Prompt the user to enter the employee code
  printf("\nEnter the employee code: ");
  // Read the integer input and store it in the emp_code field of the structure
  // pointed to by e2
  scanf("%d", &e2->emp_code);
  // Prompt the user to enter the employee name
  printf("\nEnter the employee name: ");
  // Read the string input and store it in the emp_name field of the structure
  // pointed to by e2
  scanf("%s", e2->emp_name);
  // Print the employee code and name stored in the structure
  printf("\nCode: %d Name: %s", e2->emp_code, e2->emp_name);
  // Return 0 to indicate successful program execution
  return 0;
}