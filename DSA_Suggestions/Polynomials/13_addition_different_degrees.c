/*
 * ============================================================
 * PROGRAM 13: ADDITION OF DIFFERENT DEGREES
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * When adding polynomials of different degrees, we must be 
 * careful not to exceed the bounds of the smaller array. We 
 * typically use the maximum degree as the loop limit and only 
 * add from the smaller polynomial if the current index is within 
 * its range.
 *
 * ALGORITHM:
 * 1. START
 * 2. Define P1 (degree 3) and P2 (degree 1).
 * 3. Define Result array (res) with size of the larger degree (4).
 * 4. Loop from i = 0 up to 3:
 *    a. res[i] = P1[i].
 *    b. IF i <= degree of P2:
 *       i. res[i] = res[i] + P2[i].
 * 5. Display the Summed polynomial.
 * 6. STOP
 * ============================================================
 */

#include <stdio.h>

int main() {
    int p1[] = {1, 2, 3, 4}; /* 4x^3 + 3x^2 + 2x + 1 */
    int p2[] = {5, 6};       /* 6x + 5 */
    int res[4];

    for (int i = 0; i < 4; i++) {
        res[i] = p1[i];
        if (i < 2) res[i] += p2[i];
    }

    printf("Sum Result:\n");
    for (int i = 3; i >= 0; i--) printf("%dx^%d ", res[i], i);
    printf("\n");

    return 0;
}

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * Sum Result:
 * 4x^3 + 3x^2 + 8x^1 + 6x^0 
 * ============================================================
 */
