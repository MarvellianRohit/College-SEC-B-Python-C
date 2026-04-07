/*
 * ============================================================
 * PROGRAM 4: EVALUATE A POLYNOMIAL AT A GIVEN VALUE OF x
 * ============================================================
 * Topic: Polynomials in Data Structures
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS EVALUATION?
 * Evaluation means substituting a specific value of x into the
 * polynomial and computing the numerical result.
 *
 * Example:
 *   Polynomial: 3x^2 + 5x + 7
 *   Evaluate at x = 2:
 *   = 3*(2^2) + 5*2 + 7
 *   = 3*4 + 10 + 7
 *   = 12 + 10 + 7
 *   = 29
 *
 * WE USE TWO METHODS:
 *   Method 1: Direct substitution (simple loop)
 *   Method 2: Horner's Method (more efficient, no separate power computation)
 * ============================================================
 */

#include <stdio.h>
#include <math.h>    /* For pow() function - computes x^n */

#define MAX 10

/* ---- FUNCTION: readPolynomial ---- */
void readPolynomial(float poly[], int degree) {
    int i;
    for (i = 0; i <= degree; i++) {
        printf("  Coefficient of x^%d: ", i);
        scanf("%f", &poly[i]);
    }
}

/* ---- FUNCTION: evaluateDirect ----
 * Uses direct formula: sum of (coeff * x^power) for each term
 * This is the straightforward method.
 */
float evaluateDirect(float poly[], int degree, float x) {
    float result = 0;    /* Start with sum = 0 */
    int i;

    for (i = 0; i <= degree; i++) {
        result += poly[i] * pow(x, i);
        /* pow(x, i) computes x raised to the power i */
        /* Example: pow(2, 3) = 8 */
    }
    return result;
}

/* ---- FUNCTION: evaluateHorner ----
 * Horner's Method: A smarter way to evaluate without computing powers.
 *
 * Normal form: a3*x^3 + a2*x^2 + a1*x + a0
 * Horner's:    ((a3*x + a2)*x + a1)*x + a0
 *
 * We start from the HIGHEST coefficient and multiply by x, then add next.
 * Result is the same but faster (no pow() needed).
 */
float evaluateHorner(float poly[], int degree, float x) {
    float result = poly[degree];   /* Start with the highest coefficient */
    int i;

    /* Go from degree-1 down to 0 */
    for (i = degree - 1; i >= 0; i--) {
        result = result * x + poly[i];
        /* Multiply current result by x and add next lower coefficient */
    }
    return result;
}

/* ---- FUNCTION: displayPolynomial ---- */
void displayPolynomial(float poly[], int degree) {
    int i;
    for (i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            if (i != degree) printf(" + ");
            if (i == 0)      printf("%.1f", poly[i]);
            else if (i == 1) printf("%.1fx", poly[i]);
            else             printf("%.1fx^%d", poly[i], i);
        }
    }
    printf("\n");
}

/* ---- MAIN FUNCTION ---- */
int main() {
    float poly[MAX];
    int degree;
    float x;

    printf("=== POLYNOMIAL EVALUATION ===\n\n");

    printf("Enter degree of polynomial: ");
    scanf("%d", &degree);

    printf("Enter coefficients (x^0 to x^%d):\n", degree);
    readPolynomial(poly, degree);

    printf("\nEnter the value of x to evaluate at: ");
    scanf("%f", &x);

    /* Display polynomial */
    printf("\nPolynomial: ");
    displayPolynomial(poly, degree);
    printf("Value of x = %.1f\n", x);

    /* Method 1 */
    float result1 = evaluateDirect(poly, degree, x);
    printf("\nMethod 1 (Direct Substitution): P(%.1f) = %.2f\n", x, result1);

    /* Method 2 */
    float result2 = evaluateHorner(poly, degree, x);
    printf("Method 2 (Horner's Method):     P(%.1f) = %.2f\n", x, result2);

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === POLYNOMIAL EVALUATION ===
 *
 * Enter degree of polynomial: 2
 * Enter coefficients (x^0 to x^2):
 *   Coefficient of x^0: 7
 *   Coefficient of x^1: 5
 *   Coefficient of x^2: 3
 *
 * Enter the value of x to evaluate at: 2
 *
 * Polynomial: 3.0x^2 + 5.0x + 7.0
 * Value of x = 2.0
 *
 * Method 1 (Direct Substitution): P(2.0) = 29.00
 * Method 2 (Horner's Method):     P(2.0) = 29.00
 *
 * ============================================================
 * HOW IT WORKS (Step by Step for x=2, poly = 3x^2 + 5x + 7):
 * ============================================================
 *
 * METHOD 1 (Direct):
 *   i=0: result += 7 * 2^0 = 7 * 1 = 7    -> result = 7
 *   i=1: result += 5 * 2^1 = 5 * 2 = 10   -> result = 17
 *   i=2: result += 3 * 2^2 = 3 * 4 = 12   -> result = 29
 *
 * METHOD 2 (Horner's):
 *   Start: result = 3  (highest coefficient)
 *   i=1:   result = 3*2 + 5 = 11
 *   i=0:   result = 11*2 + 7 = 29
 *
 * BOTH GIVE THE SAME ANSWER = 29
 *
 * WHY HORNER'S IS BETTER:
 *   - Direct method: needs O(n) multiplications just for pow()
 *   - Horner's method: only n multiplications total, no pow() needed
 *   - For large polynomials, Horner's is significantly faster
 *
 * TIME COMPLEXITY:
 *   Direct: O(n^2) if computing powers from scratch
 *   Horner: O(n)   -- much faster!
 * ============================================================
 */
