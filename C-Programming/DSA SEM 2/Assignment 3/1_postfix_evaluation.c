#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Define maximum size for the stack
#define MAX 100

// Declare a stack and a pointer to the top of the stack
int stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(int x) {
  // Check for stack overflow
  if (top >= MAX - 1) {
    printf("Stack Overflow\n");
    return;
  }
  // Increment top and add the element
  stack[++top] = x;
}

// Function to pop an element from the stack
int pop() {
  // Check for stack underflow
  if (top < 0) {
    printf("Stack Underflow\n");
    return -1;
  }
  // Return the element and decrement top
  return stack[top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char *exp) {
  int i;
  // Iterate through each character of the expression
  for (i = 0; exp[i]; ++i) {
    // If the character is a digit, push it onto the stack
    if (isdigit(exp[i])) {
      push(exp[i] - '0');
    }
    // If the character is an operator, pop two elements, apply the operator,
    // and push the result
    else {
      int val1 = pop();
      int val2 = pop();
      switch (exp[i]) {
      case '+':
        push(val2 + val1);
        break;
      case '-':
        push(val2 - val1);
        break;
      case '*':
        push(val2 * val1);
        break;
      case '/':
        push(val2 / val1);
        break;
      }
    }
  }
  // The final result is at the top of the stack
  return pop();
}

int main() {
  char exp[MAX];
  // Input the postfix expression from the user
  printf("Enter postfix expression: ");
  scanf("%s", exp);
  // Print the result of the evaluation
  printf("Postfix evaluation result: %d\n", evaluatePostfix(exp));
  return 0;
}
