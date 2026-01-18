/*
Question: Write a program where the computer sets a secret number, and the user
keeps guessing until they get it right, using a do-while loop.
*/

// Include standard input/output library
#include <stdio.h>

// Main function
int main() {
  // Hardcode a secret number (in a real game, you might randomize this)
  const int SECRET_NUMBER = 42;
  int guess;

  printf("I have picked a secret number.\n");

  // Do-while loop keeps asking until guess is correct
  do {
    printf("Guess the number: ");
    scanf("%d", &guess);

    // Provide feedback
    if (guess > SECRET_NUMBER) {
      printf("Too high! Try again.\n");
    } else if (guess < SECRET_NUMBER) {
      printf("Too low! Try again.\n");
    } else {
      printf("Congratulations! You guessed the correct number: %d\n",
             SECRET_NUMBER);
    }
  } while (guess != SECRET_NUMBER);

  // Return 0 for success
  return 0;
}
