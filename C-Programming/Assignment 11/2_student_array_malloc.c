/*
Question: Write a C program that:
• Uses malloc() to allocate memory for an array of n students (using the Student
structure from Q1). • Takes details for each student (name, age, marks). •
Displays all students’ details.
*/

// Include standard input/output library
#include <stdio.h>
// Include stdlib.h for malloc and free functions
#include <stdlib.h>

// Define the structure named Student
struct Student {
  // Character array for name
  char name[50];
  // Integer for age
  int age;
  // Float for marks
  float marks;
};

// Main function
int main() {
  // Declare a pointer to struct Student to handle dynamic array
  struct Student *students;
  // Declare integer variables for count and loop index
  int n, i;

  // Prompt user for number of students
  printf("Enter the number of students: ");
  // Read number of students
  scanf("%d", &n);

  // Allocate memory dynamically for n students
  // malloc returns a void pointer, which we cast to (struct Student*)
  // Total size is n * size of one struct Student
  students = (struct Student *)malloc(n * sizeof(struct Student));

  // Check if memory allocation was successful
  if (students == NULL) {
    // Print error message if allocation failed
    printf("Memory allocation failed!\n");
    // Exit program with error code 1
    return 1;
  }

  // Loop to take input for each student
  for (i = 0; i < n; i++) {
    // Print header for current student
    printf("\nEnter details for Student %d:\n", i + 1);

    // Prompt for Name
    printf("Name: ");
    // Read name into array at index i
    scanf("%s", students[i].name);

    // Prompt for Age
    printf("Age: ");
    // Read age into array at index i
    scanf("%d", &students[i].age);

    // Prompt for Marks
    printf("Marks: ");
    // Read marks into array at index i
    scanf("%f", &students[i].marks);
  }

  // Print header for output section
  printf("\n--- All Students Details ---\n");
  // Loop to display details for each student
  for (i = 0; i < n; i++) {
    // Print student number
    printf("\nStudent %d:\n", i + 1);
    // Print Name
    printf("Name: %s\n", students[i].name);
    // Print Age
    printf("Age: %d\n", students[i].age);
    // Print Marks
    printf("Marks: %.2f\n", students[i].marks);
  }

  // Free the dynamically allocated memory
  free(students);

  // Return 0 for success
  return 0;
}
