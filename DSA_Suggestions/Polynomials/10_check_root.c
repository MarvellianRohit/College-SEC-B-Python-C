/*
 * ============================================================
 * PROGRAM 10: CHECK IF A VALUE IS A ROOT
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
