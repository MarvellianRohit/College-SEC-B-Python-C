// Include the standard input/output library
#include <stdio.h>

// Define a structure named 'emp' to hold employee details
struct emp {
  // Integer variable to store employee code
  int emp_code;
  // Character array (string) to store employee name
  char emp_name[20];
};

// Main function where the program execution begins
int main() {
  // Declare an array 'arr' of 3 'struct emp' elements
  struct emp arr[3];
  // Loop 3 times to get input for each employee
  for (int i = 0; i < 3; i++) {
    // Prompt the user to enter the employee code
    printf("\nEnter the employee code: ");
    // Read the integer input and store it in the emp_code field of the i-th
    // element of the array
    scanf("%d", &arr[i].emp_code);
    // Prompt the user to enter the employee name
    printf("\nEnter the employee name: ");
    // Read the string input and store it in the emp_name field of the i-th
    // element of the array
    scanf("%s", arr[i].emp_name);
  }
  // Loop 3 times to display the stored data
  for (int i = 0; i < 3; i++) {
    // Print the code and name of the i-th employee
    printf("\nCode: %d Name: %s", arr[i].emp_code, arr[i].emp_name);
  }
  // Return 0 to indicate successful program execution
  return 0;
}