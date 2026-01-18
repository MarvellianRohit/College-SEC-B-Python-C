/*
Question: Reverse Array & Sum of Even/Odd: This program uses functions to
reverse an array and then find the sum of its even and odd elements.
*/

// Include standard input/output library
#include <stdio.h>

// Function to reverse array
void reverseArray(int arr[], int n) {
  int temp, start = 0, end = n - 1;
  while (start < end) {
    // Swap elements at start and end
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    // Move pointers
    start++;
    end--;
  }
}

// Function to calculate sum of even and odd elements
void sumEvenOdd(int arr[], int n) {
  int evenSum = 0, oddSum = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      evenSum += arr[i];
    } else {
      oddSum += arr[i];
    }
  }
  printf("\nSum of Even elements: %d\n", evenSum);
  printf("Sum of Odd elements:  %d\n", oddSum);
}

// Main function
int main() {
  int n;

  printf("Enter array size: ");
  scanf("%d", &n);
  int arr[n];

  printf("Enter %d integers:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Display original
  printf("\nOriginal Array: ");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);

  // Reverse array
  reverseArray(arr, n);

  // Display reversed
  printf("\nReversed Array: ");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);

  // Calculate and print sums
  sumEvenOdd(arr, n);

  return 0;
}
