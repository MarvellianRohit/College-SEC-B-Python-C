

#include <stdio.h>
#include <stdlib.h>
#define size 3

struct student {
  int roll, maths_marks, english_marks, rank;
  char std_name[50];
};

struct student stack[size];
int top = -1;

void push();
void pop();
void display();

void push() {
  if (top == size - 1)
    printf("\nOverflow");
  else {
    ++top;
    printf("\nEnter the roll");
    scanf("%d", &stack[top].roll);

    printf("\nEnter the maths_marks");
    scanf("%d", &stack[top].maths_marks);

    printf("\nEnter the english_marks");
    scanf("%d", &stack[top].english_marks);

    printf("\nEnter the rank");
    scanf("%d", &stack[top].rank);

    printf("\nEnter the name");
    scanf("%s", stack[top].std_name);
  }
}
void pop() {
  if (top == -1)
    printf("Underflow");
  else {
    printf("\nDeleted student roll: %d name: %s", stack[top].roll,
           stack[top].std_name);
    top--;
  }
}
void display() {
  if (top == -1)
    printf("\nNo record found");
  else {
    printf("\nStudents' details are:");
    for (int i = 0; i <= top; i++)
      printf("\nRoll: %d\tName: %s\tRank: %d", stack[i].roll, stack[i].std_name,
             stack[i].rank);
  }
}

void display_studentlist() {
  if (top == -1)
    printf("\nNo record found");
  else {
    printf("\nStudents' details are:");
    for (int i = 0; i <= top; i++)
      printf("\nRoll: %d\tName: %s", stack[i].roll, stack[i].std_name);
  }
}
void display_marks() {
  if (top == -1)
    printf("\nNo record found");
  else {
    printf("\nStudents' details are:");
    for (int i = 0; i <= top; i++) {
      int total = stack[i].maths_marks + stack[i].english_marks;
      printf("\nRoll: %d\tName: %s\tTotal Marks:%d", stack[i].roll,
             stack[i].std_name, total);
    }
  }
}

int main() {
  int ch;
  while (1) {
    printf("\n1. Push\n2. Pop\n3. Display\nEnter the choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    case 4:
      display_studentlist();
      break;
    case 5:
      display_marks();
      break;
    default:
      exit(0);
    }
  }
  return 0;
}