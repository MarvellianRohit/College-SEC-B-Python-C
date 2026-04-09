/*
 * ============================================================
 * PROGRAM 07: SUBTRACTION WITH NEGATIVE COEFFICIENTS
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * This program demonstrates how to handle subtraction when the 
 * polynomials contain negative coefficients. The logic remains 
 * the same: Result[i] = P1[i] - P2[i], but we must be careful 
 * with sign changes (e.g., subtracting -2 is the same as adding 2).
 *
 * ALGORITHM:
 * 1. START
 * 2. Define P1 and P2 with both positive and negative coefficients.
 * 3. For each index 'i':
 *    a. Calculate res[i] = p1[i] - p2[i].
 * 4. Display the resulting polynomial with proper signs.
 * 5. STOP
 * ============================================================
 */

#include <stdio.h>

int main() {
    int p1[] = {5, -2, 3}; /* 3x^2 - 2x + 5 */
    int p2[] = {10, 4, -1};/* -x^2 + 4x + 10 */
    int res[3];

    for (int i = 0; i < 3; i++) {
        res[i] = p1[i] - p2[i];
    }

    printf("Result (P1 - P2):\n  ");
    for (int i = 2; i >= 0; i--) {
        printf("%dx^%d ", res[i], i);
        if (i > 0) printf("+ ");
    }
    printf("\n");

    return 0;
}

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * Result (P1 - P2):
 *   4x^2 + -6x^1 + -5x^0 
 * ============================================================
 */
