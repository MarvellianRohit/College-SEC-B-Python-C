/*
 * ============================================================
 * PROGRAM 11: ADD AND SUBTRACT COMBINED
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * This program demonstrates performing two operations in a 
 * single step: adding two polynomials and then subtracting 
 * a third. Formula: Result = (P1 + P2) - P3.
 *
 * ALGORITHM:
 * 1. START
 * 2. Define three polynomials P1, P2, and P3.
 * 3. Initialize a Result array.
 * 4. For each index 'i':
 *    a. Calculate Result[i] = (P1[i] + P2[i]) - P3[i].
 * 5. Display the result.
 * 6. STOP
 * ============================================================
 */

#include <stdio.h>

int main() {
    int p1[] = {1, 1, 1}; /* x^2 + x + 1 */
    int p2[] = {2, 2, 2}; /* 2x^2 + 2x + 2 */
    int p3[] = {3, 3, 3}; /* 3x^2 + 3x + 3 */
    int res[3];

    /* (P1 + P2) - P3 */
    for (int i = 0; i < 3; i++) {
        res[i] = (p1[i] + p2[i]) - p3[i];
    }

    printf("Result of (P1 + P2) - P3:\n  ");
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
 * Result of (P1 + P2) - P3:
 *   0x^2 + 0x^1 + 0x^0 
 * ============================================================
 */
