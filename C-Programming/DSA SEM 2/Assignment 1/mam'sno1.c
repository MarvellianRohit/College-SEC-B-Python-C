#include <stdio.h>
#include <stdlib.h>
#define size 5

int arr[size], top = -1, data;

void push();
void pop();
void display();

void push() {
  if (top == size - 1)
    printf("Overflow");
  else {
    top++;
    printf("Enter the value: ");
    scanf("%d", &data);
    arr[top] = data;
  }
}
void pop() {
  if (top == -1)
    printf("Underflow");
  else {
    printf("Data to be deleted: %d", arr[top]);
    top--;
  }
}
void display() {
  if (top == -1)
    printf("Underflow");
  else {
    printf("The data are:");
    for (int i = 0; i <= top; i++)
      printf("\n%d", arr[i]);
  }
}

int main() {
  int ch;
  while (1) {
    printf("\n1. Push \n2. Pop \n3. Display \n Enter the input: ");
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
    default:
      exit(0);
    }
  }
  return 0;
}
