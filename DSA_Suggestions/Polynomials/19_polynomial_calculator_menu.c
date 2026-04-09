/*
 * ============================================================
 * PROGRAM 19: POLYNOMIAL CALCULATOR MENU
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
