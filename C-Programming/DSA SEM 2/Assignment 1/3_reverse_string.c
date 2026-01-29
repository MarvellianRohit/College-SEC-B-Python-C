#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
  if (top == MAX - 1) {
    printf("Stack Overflow\n");
  } else {
    top++;
    stack[top] = c;
  }
}

char pop() {
  if (top == -1) {
    printf("Stack Underflow\n");
    return '\0';
  } else {
    char c = stack[top];
    top--;
    return c;
  }
}

int main() {
  char str[MAX];

  printf("Enter a string: ");
  scanf("%[^\n]s", str); // Read string with spaces

  // Push all characters to stack
  for (int i = 0; i < strlen(str); i++) {
    push(str[i]);
  }

  printf("Reversed string: ");

  // Pop all characters and print
  while (top != -1) {
    printf("%c", pop());
  }
  printf("\n");

  return 0;
}
