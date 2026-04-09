/*
 * ============================================================
 * PROGRAM 09: EVALUATE AT MULTIPLE POINTS
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * This program calculates the value of P(x) for several 
 * different values of 'x' using a single loop. This is useful 
 * for plotting points or finding where a polynomial is close 
 * to zero.
 *
 * ALGORITHM:
 * 1. START
 * 2. Define a polynomial P(x) = x^2 + 2x + 1.
 * 3. Define an array containing the values of 'x' {0, 1, 2, -1}.
 * 4. For each value 'x' in the array:
 *    a. Calculate P(x) = (x*x) + (2*x) + 1.
 *    b. Display the result of P(x).
 * 5. STOP
 * ============================================================
 */

#include <stdio.h>
#include <math.h>

int main() {
    int poly[] = {1, 2, 1}; /* x^2 + 2x + 1 */
    float points[] = {0, 1, 2, -1};

    printf("Evaluation of x^2 + 2x + 1:\n");
    for (int i = 0; i < 4; i++) {
        float x = points[i];
        float val = (x*x) + (2*x) + 1;
        printf("  P(%.1f) = %.2f\n", x, val);
    }

    return 0;
}

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * Evaluation of x^2 + 2x + 1:
 *   P(0.0) = 1.00
 *   P(1.0) = 4.00
 *   P(2.0) = 9.00
 *   P(-1.0) = 0.00
 * ============================================================
 */
