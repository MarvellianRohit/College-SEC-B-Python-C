/*
 * ============================================================
 * PROGRAM 20: HARD MULTIPLY AND ADD: (P1*P2) + (P1*P3)
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * This program performs a complex polynomial calculation: 
 * (P1 * P2) + (P1 * P3). This is equivalent to P1 * (P2 + P3). 
 * It showcases nested loops for multiplication followed by 
 * array addition to get the final result.
 *
 * ALGORITHM:
 * 1. START
 * 2. Define P1, P2, and P3.
 * 3. Initialize prod1 and prod2 arrays to zero.
 * 4. Calculate prod1 = P1 * P2 using nested loops.
 * 5. Calculate prod2 = P1 * P3 using nested loops.
 * 6. For each index 'i':
 *    a. Result[i] = prod1[i] + prod2[i].
 * 7. Display the final polynomial.
 * 8. STOP
 * ============================================================
 */

#include <stdio.h>

int main() {
    int p1[] = {1, 1}; /* x + 1 */
    int p2[] = {2, 1}; /* x + 2 */
    int p3[] = {3, 1}; /* x + 3 */

    int prod1[3] = {0}, prod2[3] = {0}, res[3];

    /* P1 * P2 */
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            prod1[i+j] += p1[i] * p2[j];

    /* P1 * P3 */
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            prod2[i+j] += p1[i] * p3[j];

    /* (P1*P2) + (P1*P3) */
    for (int i = 0; i < 3; i++) res[i] = prod1[i] + prod2[i];

    printf("Final Hard Result:\n");
    for (int i = 2; i >= 0; i--) printf("%dx^%d ", res[i], i);
    printf("\n");

    return 0;
}

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * Result of (P1*P2) + (P1*P3):
 * 2x^2 + 7x^1 + 5x^0 
 * ============================================================
 */
