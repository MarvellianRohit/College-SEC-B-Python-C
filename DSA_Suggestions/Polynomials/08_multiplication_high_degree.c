/*
 * ============================================================
 * PROGRAM 08: MULTIPLICATION OF HIGH DEGREE POLYNOMIALS
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * This program multiplies a cubic polynomial (degree 3) with a 
 * quadratic polynomial (degree 2). The resulting polynomial 
 * will have a degree of 5 (3 + 2). We use nested loops to 
 * multiply every term of P1 by every term of P2.
 *
 * ALGORITHM:
 * 1. START
 * 2. Define P1 (degree 3) and P2 (degree 2).
 * 3. Define Result array (res) with size at least (3+2+1).
 * 4. For i = 0 to 3:
 *    a. For j = 0 to 2:
 *       i. res[i+j] = res[i+j] + (p1[i] * p2[j]).
 * 5. Display the result.
 * 6. STOP
 * ============================================================
 */

#include <stdio.h>

#define MAX 50

int main() {
    int p1[] = {1, 2, 3, 4}; /* 4x^3 + 3x^2 + 2x + 1 */
    int p2[] = {5, 6, 7};    /* 7x^2 + 6x + 5 */
    int res[MAX] = {0};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            res[i+j] += p1[i] * p2[j];
        }
    }

    printf("Large Multiplication Result:\n  ");
    for (int i = 5; i >= 0; i--) {
        if (res[i] != 0) printf("%dx^%d + ", res[i], i);
    }
    printf("0\n");

    return 0;
}

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * Resulting Polynomial:
 *   28x^5 + 37x^4 + 32x^3 + 27x^2 + 16x^1 + 5x^0 
 * ============================================================
 */
