/*
 * ============================================================
 * PROGRAM 17: SUBTRACTION THEN EVALUATE
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * This program subtracts two linear polynomials and then 
 * evaluates the resulting polynomial at a given point 'x'.
 * Formula: P_final(x) = (P1 - P2)(x).
 *
 * ALGORITHM:
 * 1. START
 * 2. Define P1 (5x + 10) and P2 (2x + 4).
 * 3. Calculate difference polynomial diff = P1 - P2.
 * 4. Define evaluation point x = 2.
 * 5. Calculate final value = diff[1]*x + diff[0].
 * 6. Display the final evaluated result.
 * 7. STOP
 * ============================================================
 */

#include <stdio.h>

int main() {
    int p1[] = {10, 5}; /* 5x + 10 */
    int p2[] = {4, 2};  /* 2x + 4 */
    int diff[2];
    int x = 2;

    for (int i = 0; i < 2; i++) diff[i] = p1[i] - p2[i];

    int val = diff[0] + (diff[1] * x);

    printf("(P1-P2) evaluated at x=2: %d\n", val);
    return 0;
}

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * (P1-P2) evaluated at x=2: 12
 * ============================================================
 */
