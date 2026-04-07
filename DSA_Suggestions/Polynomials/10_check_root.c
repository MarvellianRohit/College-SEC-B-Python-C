/*
 * ============================================================
 * PROGRAM 10: CHECK IF A VALUE IS A ROOT OF A POLYNOMIAL
 * ============================================================
 * Topic: Polynomials in Data Structures
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS A ROOT?
 * A value x = r is called a ROOT of polynomial P(x) if:
 *   P(r) = 0
 *
 * Example:
 *   P(x) = x^2 - 5x + 6
 *   Check x = 2: P(2) = 4 - 10 + 6 = 0  -> YES, 2 is a root
 *   Check x = 3: P(3) = 9 - 15 + 6 = 0  -> YES, 3 is a root
 *   Check x = 4: P(4) = 16 - 20 + 6 = 2 -> NO, 4 is not a root
 *
 * A polynomial of degree n can have at most n roots.
 * x^2 - 5x + 6 is degree 2, so it has exactly 2 roots: 2 and 3.
 *
 * This program:
 * 1. Lets the user enter a polynomial
 * 2. Lets the user check multiple candidate roots
 * ============================================================
 */

#include <stdio.h>
#include <math.h>   /* For fabs() - absolute value of float */

#define MAX 15

/* ---- FUNCTION: evaluate (Horner's Method) ---- */
float evaluate(int poly[], int degree, float x) {
    float result = poly[degree];   /* Start from highest term */
    int i;
    for (i = degree - 1; i >= 0; i--) {
        result = result * x + poly[i];
    }
    return result;
}

/* ---- FUNCTION: readPolynomial ---- */
void readPolynomial(int poly[], int degree) {
    int i;
    for (i = 0; i <= degree; i++) {
        printf("  Enter coefficient of x^%d: ", i);
        scanf("%d", &poly[i]);
    }
}

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
    printf("\n");
}

/* ---- MAIN ---- */
int main() {
    int poly[MAX];
    int degree;
    int numChecks, i;
    float candidate;

    printf("=== CHECK IF x IS A ROOT OF THE POLYNOMIAL ===\n\n");

    /* Let's use a hard example: P(x) = x^3 - 6x^2 + 11x - 6 */
    /* Roots of this polynomial are: x=1, x=2, x=3 */
    printf("Using polynomial: P(x) = x^3 - 6x^2 + 11x - 6\n");
    printf("(Coefficients: x^0=-6, x^1=11, x^2=-6, x^3=1)\n\n");

    poly[0] = -6;   /* constant term */
    poly[1] = 11;   /* coefficient of x */
    poly[2] = -6;   /* coefficient of x^2 */
    poly[3] =  1;   /* coefficient of x^3 */
    degree  =  3;

    printf("P(x) = ");
    displayWithSign(poly, degree);
    printf("\n");

    /* Check several values */
    printf("How many values do you want to check? ");
    scanf("%d", &numChecks);

    printf("\n");
    for (i = 0; i < numChecks; i++) {
        printf("Enter candidate value x: ");
        scanf("%f", &candidate);

        float result = evaluate(poly, degree, candidate);

        printf("  P(%.2f) = %.4f  -->  ", candidate, result);

        /* If result is very close to 0, it's a root */
        if (fabs(result) < 0.0001) {
            printf("YES! x = %.2f is a ROOT of P(x).\n\n", candidate);
        } else {
            printf("NO. x = %.2f is NOT a root.\n\n", candidate);
        }
    }

    printf("TIP: Try x = 1, 2, and 3 to find all roots of this polynomial!\n");

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === CHECK IF x IS A ROOT OF THE POLYNOMIAL ===
 *
 * Using polynomial: P(x) = x^3 - 6x^2 + 11x - 6
 * (Coefficients: x^0=-6, x^1=11, x^2=-6, x^3=1)
 *
 * P(x) = x^3 - 6x^2 + 11x - 6
 *
 * How many values do you want to check? 5
 *
 * Enter candidate value x: 1
 *   P(1.00) = 0.0000  -->  YES! x = 1.00 is a ROOT of P(x).
 *
 * Enter candidate value x: 2
 *   P(2.00) = 0.0000  -->  YES! x = 2.00 is a ROOT of P(x).
 *
 * Enter candidate value x: 3
 *   P(3.00) = 0.0000  -->  YES! x = 3.00 is a ROOT of P(x).
 *
 * Enter candidate value x: 4
 *   P(4.00) = 6.0000  -->  NO. x = 4.00 is NOT a root.
 *
 * Enter candidate value x: 0
 *   P(0.00) = -6.0000 -->  NO. x = 0.00 is NOT a root.
 *
 * TIP: Try x = 1, 2, and 3 to find all roots of this polynomial!
 *
 * ============================================================
 * HOW IT WORKS:
 * ============================================================
 * We use the FACTOR THEOREM from mathematics:
 *   "x = r is a root of P(x) if and only if P(r) = 0"
 *
 * Algorithm:
 * 1. User enters a value x = candidate
 * 2. We compute P(candidate) using Horner's method
 * 3. If result == 0, it's a root; otherwise it's not
 *
 * WHY fabs() < 0.0001 instead of == 0?
 *   Float arithmetic has tiny errors.
 *   e.g., 0.1 + 0.2 = 0.30000000004 in a computer.
 *   So we check if result is "very close to 0" rather than exactly 0.
 *   fabs() returns the absolute value (removes negative sign).
 *
 * THE POLYNOMIAL x^3 - 6x^2 + 11x - 6:
 *   It factors as (x-1)(x-2)(x-3)
 *   So its roots are exactly x = 1, 2, 3.
 *   This is a great example because all roots are whole numbers!
 * ============================================================
 */
