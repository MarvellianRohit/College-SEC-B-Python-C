#include <stdio.h>
#include <stdlib.h>
#define size 5
int ch;
int q[size];
int rear = -1;
int front = -1;

void Insert_queue();
void Delete_queue();
void Display_queue();

void Insert_queue() {
  if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
    printf("\n Overflow");
    return;
  }
  if (front == -1) {
    front = 0;
    rear = 0;
  } else {
    if (rear == size - 1)
      rear = 0;
    else
      rear++;
  }

  printf("\n Input the element :");
  scanf("%d", &ch);
  q[rear] = ch;
}

void Delete_queue() {
  if (front == -1) {
    printf("\nUnderflow");
    return;
  }
  ch = q[front];
  printf("\n Element deleted %d:", ch);
  if (front == rear) {
    front = -1;
    rear = -1;
  } else {
    if (front == size - 1)
      front = 0;
    else
      front++;
  }
}

void Display_queue() {
  int i;
  if (front == -1) {
    printf("\nUnderflow");
    return;
  }
  if (rear >= front) {
    for (i = front; i <= rear; i++)
      printf(" %d \n", q[i]);
  } else {
    for (i = front; i < size; i++)
      printf(" %d \n", q[i]);
    for (i = 0; i <= rear; i++)
      printf(" %d \n", q[i]);
  }
}

void main() {
  int choice;
  while (1) {
    printf("\nInsert->1 \nDelete->2 \nDisplay->3 \nQuit-.4:");
    printf("\nInput the choice : ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      Insert_queue();
      break;
    case 2:
      Delete_queue();
      break;
    case 3:
      Display_queue();
      break;

    case 4:
      exit(0);
    }
  }
}
