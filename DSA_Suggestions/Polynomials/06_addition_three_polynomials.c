/*
 * ============================================================
 * PROGRAM 06: ADDITION OF THREE POLYNOMIALS
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * This program demonstrates adding three separate polynomials 
 * together. The process is the same as adding two: we simply 
 * accumulate the coefficients of matching powers from all 
 * three polynomials into a single result array.
 *
 * ALGORITHM:
 * 1. START
 * 2. Define three polynomials P1, P2, and P3 in arrays.
 * 3. Initialize a Result array (res) with zeros.
 * 4. Add P1 to res, then P2 to res, then P3 to res.
 * 5. Display the final combined polynomial.
 * 6. STOP
 * ============================================================
 */

#include <stdio.h>

int main() {
    int p1[] = {1, 2, 3}; /* 3x^2 + 2x + 1 */
    int p2[] = {4, 5};    /* 5x + 4 */
    int p3[] = {2, 0, 1}; /* x^2 + 2 */
    int res[5] = {0};

    for (int i = 0; i < 3; i++) res[i] += p1[i];
    for (int i = 0; i < 2; i++) res[i] += p2[i];
    for (int i = 0; i < 3; i++) res[i] += p3[i];

    printf("Result of P1 + P2 + P3:\n  ");
    for (int i = 2; i >= 0; i--) {
        if (res[i] != 0) printf("%dx^%d + ", res[i], i);
    }
    printf("0\n");

    return 0;
}

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * Resulting Polynomial:
 *   4x^2 + 7x^1 + 7x^0 
 * ============================================================
 */
