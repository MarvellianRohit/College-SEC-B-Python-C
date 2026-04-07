/*
 * ============================================================
 * PROGRAM 19: USER-INPUT POLYNOMIAL — ALL FOUR OPERATIONS
 * ============================================================
 * Topic: Polynomials in Data Structures
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * This is a MENU-DRIVEN program where the user:
 *   1. Enters two polynomials
 *   2. Chooses which operation to perform (add/subtract/multiply)
 *   3. Optionally evaluates the result at some x
 *
 * This is a practical application combining all the concepts
 * from the previous programs into one interactive program.
 * ============================================================
 */

#include <stdio.h>
#include <math.h>

#define MAX 20

/* Polynomial state */
int poly1[MAX], poly2[MAX], result[MAX];
int deg1, deg2, degResult;

/* ---- FUNCTION: displayWithSign ---- */
void displayWithSign(int poly[], int degree) {
    int i, first = 1;
    for (i = degree; i >= 0; i--) {
        if (poly[i] == 0) continue;
        if (first) {
            if (i == 0)      printf("%d", poly[i]);
            else if (i == 1) printf("%dx", poly[i]);
            else             printf("%dx^%d", poly[i], i);
            first = 0;
        } else {
            if (poly[i] > 0) {
                printf(" + ");
                if (i == 0)      printf("%d", poly[i]);
                else if (i == 1) printf("%dx", poly[i]);
                else             printf("%dx^%d", poly[i], i);
            } else {
                printf(" - ");
                int a = -poly[i];
                if (i == 0)      printf("%d", a);
                else if (i == 1) printf("%dx", a);
                else             printf("%dx^%d", a, i);
            }
        }
    }
    if (first) printf("0");
    printf("\n");
}

/* ---- FUNCTION: readPolynomial ---- */
void readPolynomial(int poly[], int *degree, int num) {
    printf("Enter degree of Polynomial %d: ", num);
    scanf("%d", degree);
    printf("Enter coefficients for P%d (from x^0 to x^%d):\n", num, *degree);
    int i;
    for (i = 0; i <= *degree; i++) {
        printf("  Coefficient of x^%d: ", i);
        scanf("%d", &poly[i]);
    }
}

/* ---- FUNCTION: addPoly ---- */
int addPoly(int p1[], int d1, int p2[], int d2, int out[]) {
    int i;
    int maxD = (d1 > d2) ? d1 : d2;
    for (i = 0; i <= maxD; i++) out[i] = 0;
    for (i = 0; i <= d1; i++) out[i] += p1[i];
    for (i = 0; i <= d2; i++) out[i] += p2[i];
    return maxD;
}

/* ---- FUNCTION: subtractPoly ---- */
int subtractPoly(int p1[], int d1, int p2[], int d2, int out[]) {
    int i;
    int maxD = (d1 > d2) ? d1 : d2;
    for (i = 0; i <= maxD; i++) out[i] = 0;
    for (i = 0; i <= d1; i++) out[i] = p1[i];
    for (i = 0; i <= d2; i++) out[i] -= p2[i];
    return maxD;
}

/* ---- FUNCTION: multiplyPoly ---- */
int multiplyPoly(int p1[], int d1, int p2[], int d2, int out[]) {
    int i, j;
    int resultDeg = d1 + d2;
    for (i = 0; i <= resultDeg; i++) out[i] = 0;
    for (i = 0; i <= d1; i++) {
        for (j = 0; j <= d2; j++) {
            out[i + j] += p1[i] * p2[j];
        }
    }
    return resultDeg;
}

/* ---- FUNCTION: evaluate ---- */
float evaluate(int poly[], int degree, float x) {
    float res = poly[degree];
    int i;
    for (i = degree - 1; i >= 0; i--) {
        res = res * x + poly[i];
    }
    return res;
}

/* ---- MAIN ---- */
int main() {
    int choice;
    char again;

    printf("===================================================\n");
    printf("    POLYNOMIAL CALCULATOR (All 3 Operations)\n");
    printf("===================================================\n\n");

    /* Read the two polynomials once */
    readPolynomial(poly1, &deg1, 1);
    printf("\n");
    readPolynomial(poly2, &deg2, 2);

    printf("\nP1 = "); displayWithSign(poly1, deg1);
    printf("P2 = "); displayWithSign(poly2, deg2);

    do {
        /* Show menu */
        printf("\n----- MENU -----\n");
        printf("1. P1 + P2\n");
        printf("2. P1 - P2\n");
        printf("3. P1 * P2\n");
        printf("4. Evaluate P1 at some x\n");
        printf("5. Evaluate P2 at some x\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                degResult = addPoly(poly1, deg1, poly2, deg2, result);
                printf("Result (P1 + P2) = ");
                displayWithSign(result, degResult);
                break;

            case 2:
                degResult = subtractPoly(poly1, deg1, poly2, deg2, result);
                printf("Result (P1 - P2) = ");
                displayWithSign(result, degResult);
                break;

            case 3:
                degResult = multiplyPoly(poly1, deg1, poly2, deg2, result);
                printf("Result (P1 * P2) = ");
                displayWithSign(result, degResult);
                printf("(Degree of result = %d)\n", degResult);
                break;

            case 4: {
                float x;
                printf("Enter value of x: ");
                scanf("%f", &x);
                float val = evaluate(poly1, deg1, x);
                printf("P1(%.2f) = %.4f\n", x, val);
                break;
            }

            case 5: {
                float x;
                printf("Enter value of x: ");
                scanf("%f", &x);
                float val = evaluate(poly2, deg2, x);
                printf("P2(%.2f) = %.4f\n", x, val);
                break;
            }

            default:
                printf("Invalid choice. Please choose 1-5.\n");
        }

        printf("\nDo another operation? (y/n): ");
        scanf(" %c", &again);   /* Space before %c to skip whitespace */

    } while (again == 'y' || again == 'Y');

    printf("\nGoodbye!\n");

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * ===================================================
 *     POLYNOMIAL CALCULATOR (All 3 Operations)
 * ===================================================
 *
 * Enter degree of Polynomial 1: 3
 * Enter coefficients for P1 (from x^0 to x^3):
 *   Coefficient of x^0: -4
 *   Coefficient of x^1: 3
 *   Coefficient of x^2: -2
 *   Coefficient of x^3: 5
 *
 * Enter degree of Polynomial 2: 2
 * Enter coefficients for P2 (from x^0 to x^2):
 *   Coefficient of x^0: 7
 *   Coefficient of x^1: -1
 *   Coefficient of x^2: 3
 *
 * P1 = 5x^3 - 2x^2 + 3x - 4
 * P2 = 3x^2 - x + 7
 *
 * ----- MENU -----
 * 1. P1 + P2
 * 2. P1 - P2
 * 3. P1 * P2
 * 4. Evaluate P1 at some x
 * 5. Evaluate P2 at some x
 * Enter your choice (1-5): 3
 * Result (P1 * P2) = 15x^5 - 11x^4 + 40x^3 - 25x^2 + 17x - 28
 * (Degree of result = 5)
 *
 * Do another operation? (y/n): y
 *
 * ----- MENU -----
 * Enter your choice (1-5): 4
 * Enter value of x: 2
 * P1(2.00) = 30.0000
 *
 * Do another operation? (y/n): n
 * Goodbye!
 *
 * ============================================================
 * HOW IT WORKS:
 * ============================================================
 * MENU-DRIVEN PROGRAMS use a loop + switch structure:
 *   1. Show menu of options
 *   2. Read user choice
 *   3. switch (choice) { case 1: ... case 2: ... }
 *   4. Ask if user wants to continue
 *   5. Loop back to step 1 if yes
 *
 * All the polynomial logic (add, subtract, multiply, evaluate)
 * is already written as separate functions. The menu just
 * calls them based on the user's choice.
 *
 * KEY C CONCEPT — 'do...while' loop:
 *   The loop body executes at least ONCE before checking the condition.
 *   Perfect for menus: show menu first, then ask "again?".
 *
 * KEY C CONCEPT — switch statement:
 *   Efficient alternative to if-else chains when comparing one
 *   variable against multiple constant values.
 * ============================================================
 */
