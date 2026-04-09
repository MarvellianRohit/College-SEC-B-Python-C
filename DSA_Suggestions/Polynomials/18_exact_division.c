/*
 * ============================================================
 * PROGRAM 18: EXACT DIVISION CHECK
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * A polynomial P(x) is exactly divisible by (x - a) if the 
 * remainder is zero (P(a) = 0). This program checks for 
 * exact divisibility by evaluating the polynomial at the 
 * divisor's root.
 *
 * ALGORITHM:
 * 1. START
 * 2. Define dividend P(x) = x^2 - 4 and divisor root x = 2.
 * 3. Evaluate P(2): (-4) + (0 * 2) + (1 * 2 * 2).
 * 4. IF remainder is 0:
 *    a. Print "Exactly divisible".
 * 5. ELSE:
 *    a. Print "Not exactly divisible" and the remainder.
 * 6. STOP
 * ============================================================
 */

#include <stdio.h>

int main() {
    /* Check if x^2 - 4 is exactly divisible by x - 2 */
    int poly[] = {-4, 0, 1};
    int x = 2;

    int remainder = (-4) + (0 * x) + (1 * x * x);

    if (remainder == 0) {
        printf("x^2 - 4 IS exactly divisible by x - 2\n");
    } else {
        printf("Not exactly divisible. Remainder: %d\n", remainder);
    }

    return 0;
}

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * x^2 - 4 IS exactly divisible by x - 2
 * ============================================================
 */
