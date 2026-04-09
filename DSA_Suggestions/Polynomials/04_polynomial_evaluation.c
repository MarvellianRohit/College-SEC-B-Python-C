/*
 * ============================================================
 * PROGRAM 04: POLYNOMIAL EVALUATION
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * This program calculates the value of a polynomial for a 
 * given value of 'x'. For example, if P(x) = 3x^2 + 2x + 5, 
 * then evaluating at x = 2 gives: P(2) = 3(2^2) + 2(2) + 5 = 21. 
 *
 * ALGORITHM:
 * 1. START
 * 2. Define the polynomial coefficients in an array.
 * 3. Get the value of 'x' to evaluate at.
 * 4. Initialize result = 0.
 * 5. Loop i from 0 to degree:
 *    a. result = result + (coeff[i] * power(x, i)).
 * 6. Print the final result.
 * 7. STOP
 * ============================================================
 */

#include <stdio.h>
#include <math.h>

int main() {
    int poly[] = {5, 2, 3}; /* 3x^2 + 2x + 5 */
    int degree = 2;
    float x, result = 0;

    printf("=== POLYNOMIAL EVALUATION ===\n");
    printf("Polynomial: 3x^2 + 2x + 5\n\n");

    printf("Enter value of x: ");
    scanf("%f", &x);

    /* Evaluation loop */
    for (int i = 0; i <= degree; i++) {
        result += poly[i] * pow(x, i);
    }

    printf("\nResult of P(%.1f) is: %.2f\n", x, result);

    return 0;
}

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * === POLYNOMIAL EVALUATION ===
 *
 * Polynomial: 3x^2 + 2x^1 + 5x^0 
 * Enter the value of x: 2
 * Result of P(2) = 21.00
 * ============================================================
 */
