/*
 * ============================================================
 * PROGRAM 05: POLYNOMIAL DIVISION (SYNTHETIC DIVISION)
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * Dividing a polynomial P(x) by (x - a).
 * This uses a simplified method to find the QUOTIENT and REMAINDER.
 * ============================================================
 */

#include <stdio.h>

int main() {
    /* Divide P(x) = 3x^2 + 2x + 5 by (x - 2) */
    int poly[] = {5, 2, 3}; 
    int degree = 2;
    int divisor = 2; /* we divide by (x - 2) */
    
    int quotient[2];
    int remainder;

    printf("=== POLYNOMIAL DIVISION ===\n");
    printf("P(x) = 3x^2 + 2x + 5, Divisor = (x - 2)\n\n");

    /* Synthetic Division Steps */
    remainder = poly[degree]; /* Start with the leading coefficient */
    
    for (int i = degree - 1; i >= 0; i--) {
        quotient[i] = remainder;
        remainder = (remainder * divisor) + poly[i];
    }

    printf("Quotient: %dx + %d\n", quotient[1], quotient[0]);
    printf("Remainder: %d\n", remainder);

    return 0;
}
