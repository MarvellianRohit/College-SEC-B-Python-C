/*
Question: Write a C program to define a structure named Student with the
following members: • name (string) • age (int) • marks (float) Take input for
one student and display the details.
*/

// Include standard input/output library
#include <stdio.h>

// Define the structure named Student
struct Student {
  // Character array to store name (max 50 chars)
  char name[50];
  // Integer variable to store age
  int age;
  // Float variable to store marks
  float marks;
};

// Main function
int main() {
  // Declare a variable 's1' of type 'struct Student'
  struct Student s1;

  // Prompt user for input details
  printf("Enter details for the student:\n");

  // Prompt for Name
  printf("Enter Name: ");
  // Read string input for name
  scanf("%s", s1.name);

  // Prompt for Age
  printf("Enter Age: ");
  // Read integer input for age
  scanf("%d", &s1.age);

  // Prompt for Marks
  printf("Enter Marks: ");
  // Read float input for marks
  scanf("%f", &s1.marks);

  // Print a separator line
  printf("\n--- Student Details ---\n");
  // Print the student's name
  printf("Name: %s\n", s1.name);
  // Print the student's age
  printf("Age: %d\n", s1.age);
  // Print the student's marks formatted to 2 decimal places
  printf("Marks: %.2f\n", s1.marks);

  // Return 0 to indicate successful execution
  return 0;
}
