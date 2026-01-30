#include <stdio.h>
#include <stdlib.h>
#define size 5

int top = -1, data;

void push(int arr[size], int item);
int pop(int arr[size]);
void display(int arr[size]);

void push(int arr[size], int item) {
  if (top == size - 1)
    printf("Overflow");
  else {
    top++;
    arr[top] = item;
  }
}
int pop(int arr[size]) {
  if (top == -1)
    printf("Underflow");
  else {
    data = arr[top];
    top--;
  }
  return data;
}
void display(int arr[size]) {
  if (top == -1)
    printf("Underflow");
  else {
    printf("The data are:");
    for (int i = 0; i <= top; i++)
      printf("\n%d", arr[i]);
  }
}

int main() {
  int ch, arr[size];
  while (1) {
    printf("\n1. Push \n2. Pop \n3. Display \n Enter the input: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      printf("Enter the value: ");
      scanf("%d", &data);
      push(arr, data);
      break;
    case 2:
      data = pop(arr);
      printf("Data to be deleted: %d", data);
      break;
    case 3:
      display(arr);
      break;
    default:
      exit(0);
    }
  }
  return 0;
}
