/*
 * ============================================================
 * PROGRAM 15: POLYNOMIAL SQUARE (P1 * P1)
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * This program calculates the square of a polynomial by 
 * multiplying it by itself. Squaring a polynomial P(x) is 
 * equivalent to P(x) * P(x).
 * Example: (x + 3)^2 = (x + 3) * (x + 3) = x^2 + 6x + 9.
 *
 * ALGORITHM:
 * 1. START
 * 2. Define polynomial P1 (x + 3).
 * 3. Initialize Result array (res) to all zeros.
 * 4. Multiply P1 by P1 using nested loops: res[i+j] += p1[i] * p1[j].
 * 5. Display the squared polynomial.
 * 6. STOP
 * ============================================================
 */

#include <stdio.h>

int main() {
    int p1[] = {3, 1}; /* x + 3 */
    int res[3] = {0};

    /* P1 * P1 */
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res[i+j] += p1[i] * p1[j];
        }
    }

    printf("Square of (x + 3):\n");
    for (int i = 2; i >= 0; i--) printf("%dx^%d ", res[i], i);
    printf("\n");

    return 0;
}

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * Square of (x + 3):
 * 1x^2 + 6x^1 + 9x^0 
 * ============================================================
 */
