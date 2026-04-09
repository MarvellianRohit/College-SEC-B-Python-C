/*
 * ============================================================
 * PROGRAM 12: MULTIPLY THEN EVALUATE
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * This program demonstrates a sequence of two operations: first, 
 * it multiplies two linear polynomials together, and then it 
 * evaluates the resulting polynomial for a specific value of 'x'.
 * Formula: P_final(x) = (P1 * P2)(x).
 *
 * ALGORITHM:
 * 1. START
 * 2. Define P1 (x + 1) and P2 (x + 2).
 * 3. Initialize Result array (res) to all zeros.
 * 4. Multiply P1 and P2 using nested loops: res[i+j] += p1[i] * p2[j].
 * 5. Define evaluation point x = 3.
 * 6. Calculate P_final(3) = res[2]*x^2 + res[1]*x^1 + res[0].
 * 7. Display the product and the final evaluated result.
 * 8. STOP
 * ============================================================
 */

#include <stdio.h>

int main() {
    int p1[] = {1, 1}; /* x + 1 */
    int p2[] = {2, 1}; /* x + 2 */
    int res[3] = {0};
    int x = 3;

    /* Multiply */
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res[i+j] += p1[i] * p2[j];
        }
    }

    /* Evaluate at x = 3 */
    int val = res[0] + (res[1] * x) + (res[2] * x * x);

    printf("P1*P2 eval at x=3: %d\n", val);
    return 0;
}

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * Result of (x + 1) * (x + 2): 1x^2 + 3x^1 + 2x^0 
 * Value at x = 3: 20
 * ============================================================
 */
