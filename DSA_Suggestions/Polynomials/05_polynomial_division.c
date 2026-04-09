/*
 * ============================================================
 * PROGRAM 05: POLYNOMIAL DIVISION (SYNTHETIC DIVISION)
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * This program performs Synthetic Division, which is a shortcut 
 * method of dividing a polynomial by a linear factor of the 
 * form (x - a). It calculates the coefficients of the quotient 
 * polynomial and the final remainder.
 *
 * ALGORITHM:
 * 1. START
 * 2. Define the dividend polynomial P(x) and the divisor constant 'a'.
 * 3. Take the first coefficient of P(x) as the first coefficient of 
 *    the quotient.
 * 4. For each subsequent coefficient:
 *    a. Multiply 'a' with the previous quotient coefficient and 
 *       add it to the current dividend coefficient.
 * 5. The last result is the remainder; the others are quotient 
 *    coefficients.
 * 6. STOP
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

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * === POLYNOMIAL SYNTHETIC DIVISION ===
 * P(x) = 3x^2 + 2x^1 + 5x^0 
 * Divisor = (x - 2)
 *
 * Quotient: 3x^1 + 8x^0 
 * Remainder: 21
 * ============================================================
 */
