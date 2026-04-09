/*
 * ============================================================
 * PROGRAM 04: POLYNOMIAL EVALUATION
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * Evaluation means finding the value of P(x) for a given x.
 * Example: if P(x) = 2x + 5, then P(2) = 2(2) + 5 = 9.
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
