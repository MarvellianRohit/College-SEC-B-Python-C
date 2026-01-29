#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Defined as verified struct with typedef to support both 'struct Student' and
// 'Student' usages
typedef struct Student {
  int roll;
  char std_name[50];
  float maths_marks;
  float english_marks;
  int rank;
} Student;

Student stack[MAX];
int top = -1;

void push() {
  if (top == MAX - 1) {
    printf("Stack Overflow! Cannot add more students.\n");
    return;
  }
  Student s;
  printf("\nEnter details for new student:\n");
  printf("Roll Number: ");
  scanf("%d", &s.roll);
  printf("Name: ");
  scanf(" %[^\n]s", s.std_name); // Read string with spaces
  printf("Maths Marks: ");
  scanf("%f", &s.maths_marks);
  printf("English Marks: ");
  scanf("%f", &s.english_marks);
  s.rank = 0; // Placeholder, not calculated yet

  top++;
  stack[top] = s;
  printf("Student added successfully.\n");
}

void pop() {
  if (top == -1) {
    printf("Stack Underflow! No students to delete.\n");
    return;
  }
  printf("Deleted Student Record: Roll: %d, Name: %s\n", stack[top].roll,
         stack[top].std_name);
  top--;
}

void display_records() {
  if (top == -1) {
    printf("No records found.\n");
    return;
  }
  printf("\n--- Student Records (Stack Order) ---\n");
  printf("%-5s %-20s %-10s %-10s\n", "Roll", "Name", "Maths", "English");
  for (int i = top; i >= 0; i--) {
    printf("%-5d %-20s %-10.2f %-10.2f\n", stack[i].roll, stack[i].std_name,
           stack[i].maths_marks, stack[i].english_marks);
  }
}

// Function to calculate total marks
float calculate_total(Student s) { return s.maths_marks + s.english_marks; }

void display_total_marks() {
  if (top == -1) {
    printf("No records found.\n");
    return;
  }
  printf("\n--- Total Marks for Each Student ---\n");
  printf("%-5s %-20s %-10s\n", "Roll", "Name", "Total Marks");
  for (int i = top; i >= 0; i--) {
    float total = calculate_total(stack[i]);
    printf("%-5d %-20s %-10.2f\n", stack[i].roll, stack[i].std_name, total);
  }
}

// Helper to copy stack to array for sorting without disturbing stack
void get_stack_contents(Student arr[], int *count) {
  *count = top + 1;
  for (int i = 0; i <= top; i++) {
    arr[i] = stack[i];
  }
}

void display_sorted_roll() {
  if (top == -1) {
    printf("No records found.\n");
    return;
  }
  Student temp[MAX];
  int n;
  get_stack_contents(temp, &n);

  // Bubble Sort by Roll No
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (temp[j].roll > temp[j + 1].roll) {
        Student t = temp[j];
        temp[j] = temp[j + 1];
        temp[j + 1] = t;
      }
    }
  }

  printf("\n--- Student Records (Sorted by Roll No) ---\n");
  printf("%-5s %-20s %-10s %-10s\n", "Roll", "Name", "Maths", "English");
  for (int i = 0; i < n; i++) {
    printf("%-5d %-20s %-10.2f %-10.2f\n", temp[i].roll, temp[i].std_name,
           temp[i].maths_marks, temp[i].english_marks);
  }
}

void display_sorted_marks_desc() {
  if (top == -1) {
    printf("No records found.\n");
    return;
  }
  Student temp[MAX];
  int n;
  get_stack_contents(temp, &n);

  // Bubble Sort by Total Marks Descending
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (calculate_total(temp[j]) < calculate_total(temp[j + 1])) {
        Student t = temp[j];
        temp[j] = temp[j + 1];
        temp[j + 1] = t;
      }
    }
  }

  printf("\n--- Student Records (Sorted by Total Marks Descending) ---\n");
  printf("%-5s %-20s %-10s\n", "Roll", "Name", "Total Marks");
  for (int i = 0; i < n; i++) {
    printf("%-5d %-20s %-10.2f\n", temp[i].roll, temp[i].std_name,
           calculate_total(temp[i]));
  }
}

int main() {
  int choice;
  while (1) {
    printf("\n--- Student Record Management (Stack) ---\n");
    printf("1. Push Student Record\n");
    printf("2. Pop Student Record\n");
    printf("3. Display Records (Stack Order)\n");
    printf("4. Display Records Sorted by Roll No\n");
    printf("5. Calculate & Display Total Marks\n");
    printf("6. Display Students by Marks (Descending)\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      display_records();
      break;
    case 4:
      display_sorted_roll();
      break;
    case 5:
      display_total_marks();
      break;
    case 6:
      display_sorted_marks_desc();
      break;
    case 7:
      exit(0);
    default:
      printf("Invalid choice!\n");
    }
  }
  return 0;
}
