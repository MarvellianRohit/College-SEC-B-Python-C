/*
 * ============================================================
 * PROGRAM 07: SUBTRACTION WITH NEGATIVE COEFFICIENTS
 * ============================================================
 * Topic: Polynomials (Simplified Version)
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
