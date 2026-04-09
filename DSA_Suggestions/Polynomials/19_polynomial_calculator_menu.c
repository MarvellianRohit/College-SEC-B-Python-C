/*
 * ============================================================
 * PROGRAM 19: POLYNOMIAL CALCULATOR MENU
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * This program is a structural template for a polynomial 
 * calculator. It uses a switch-case menu to allow the user 
 * to choose between different operations like addition, 
 * subtraction, and multiplication.
 *
 * ALGORITHM:
 * 1. START
 * 2. Display the calculator menu options.
 * 3. Input the user's choice.
 * 4. SWITCH (choice):
 *    a. CASE 1: Display "You chose Addition".
 *    b. CASE 2: Display "You chose Subtraction".
 *    c. CASE 3: Display "You chose Multiplication".
 *    d. DEFAULT: Display "Invalid choice".
 * 5. STOP
 * ============================================================
 */

#include <stdio.h>

int main() {
    int choice;
    printf("--- POLYNOMIAL CALC MENU ---\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: printf("You chose Addition\n"); break;
        case 2: printf("You chose Subtraction\n"); break;
        case 3: printf("You chose Multiplication\n"); break;
        default: printf("Invalid choice\n");
    }

    return 0;
}

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * --- POLYNOMIAL CALC MENU ---
 * 1. Add
 * 2. Subtract
 * 3. Multiply
 * Choice: 1
 * You chose Addition
 * ============================================================
 */
