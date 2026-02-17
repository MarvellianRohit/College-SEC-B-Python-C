#include <stdio.h>
#include <string.h>

// Define maximum size for the stack
#define MAX 100

// Declare a stack and a pointer to the top of the stack
char stack[MAX];
int top = -1;

// Function to push a character onto the stack
void push(char x) {
  // Check for stack overflow
  if (top >= MAX - 1) {
    printf("Stack Overflow\n");
    return;
  }
  // Increment top and add the character
  stack[++top] = x;
}

// Function to pop a character from the stack
char pop() {
  // Check for stack underflow
  if (top < 0) {
    return '\0';
  }
  // Return the character and decrement top
  return stack[top--];
}

// Function to check if the brackets in an expression are balanced
int isBalanced(char *exp) {
  int i;
  // Iterate through each character of the expression
  for (i = 0; exp[i]; i++) {
    // If an opening bracket is found, push it onto the stack
    if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
      push(exp[i]);
    }
    // If a closing bracket is found, check if it matches the top of the stack
    else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
      char topChar = pop();
      // If the stack is empty or the brackets don't match, it's unbalanced
      if ((exp[i] == ')' && topChar != '(') ||
          (exp[i] == ']' && topChar != '[') ||
          (exp[i] == '}' && topChar != '{')) {
        return 0;
      }
    }
  }
  // If the stack is empty at the end, the expression is balanced
  return (top == -1);
}

int main() {
  char exp[MAX];
  // Input the expression from the user
  printf("Enter an expression: ");
  scanf("%s", exp);
  // Print whether the expression is balanced or not
  if (isBalanced(exp)) {
    printf("Balanced\n");
  } else {
    printf("Not Balanced\n");
  }
  return 0;
}
