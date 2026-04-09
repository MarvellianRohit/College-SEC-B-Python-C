/*
 * ============================================================
 * PROGRAM 14: ADDITION THEN MULTIPLY
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * This program demonstrates a nested polynomial operation: 
 * (P1 + P2) * P3. First, we add P1 and P2 to get an intermediate 
 * sum polynomial, and then we multiply that sum by P3 to get the 
 * final result.
 *
 * ALGORITHM:
 * 1. START
 * 2. Define P1, P2, and P3.
 * 3. Calculate sum = P1 + P2.
 * 4. Initialize Result (res) array to zero.
 * 5. Multiply sum and P3 using nested loops: res[i+j] += sum[i] * p3[j].
 * 6. Display the final polynomial.
 * 7. STOP
 * ============================================================
 */

#include <stdio.h>

int main() {
    int p1[] = {1, 1}; /* x + 1 */
    int p2[] = {2, 1}; /* x + 2 */
    int p3[] = {1, 1}; /* x + 1 */
    int sum[2], res[3] = {0};

    /* sum = P1 + P2 */
    for (int i = 0; i < 2; i++) sum[i] = p1[i] + p2[i];

    /* res = sum * P3 */
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res[i+j] += sum[i] * p3[j];
        }
    }

    printf("Result of (P1+P2)*P3:\n");
    for (int i = 2; i >= 0; i--) printf("%dx^%d ", res[i], i);
    printf("\n");

    return 0;
}

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * Result of (P1 + P2) * P3:
 * 3x^2 + 5x^1 + 2x^0 
 * ============================================================
 */
