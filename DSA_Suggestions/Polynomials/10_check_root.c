/*
 * ============================================================
 * PROGRAM 10: CHECK IF A VALUE IS A ROOT
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * A value 'x' is called a ROOT of polynomial P(x) if P(x) = 0. 
 * This program checks whether a given value 'x' makes the 
 * polynomial equal to zero. 
 * Example: For x^2 - 1, x = 1 is a root because 1^2 - 1 = 0.
 *
 * ALGORITHM:
 * 1. START
 * 2. Define the polynomial P(x).
 * 3. Define the value 'x' to check.
 * 4. Evaluate P(x).
 * 5. IF value is 0:
 *    a. Print "x IS a root".
 * 6. ELSE:
 *    a. Print "x is NOT a root".
 * 7. STOP
 * ============================================================
 */

#include <stdio.h>

int main() {
    int poly[] = {-6, 5, -2, 1}; /* x^3 - 2x^2 + 5x - 6 */
    int x = 2; /* Check if 2 is a root */
    
    int val = (x*x*x) - (2*x*x) + (5*x) - 6;

    printf("Checking P(x) = x^3 - 2x^2 + 5x - 6 for x = %d\n", x);
    if (val == 0) {
        printf("  RESULT: %d IS a root because P(%d) = 0\n", x, x);
    } else {
        printf("  RESULT: %d is NOT a root because P(%d) = %d\n", x, x, val);
    }

    return 0;
}

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * Checking P(x) = x^3 - 2x^2 + 5x - 6 for x = 2
 *   RESULT: 2 is NOT a root because P(2) = 4
 * ============================================================
 */
