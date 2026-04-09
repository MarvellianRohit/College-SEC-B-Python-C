/*
 * ============================================================
 * PROGRAM 18: EXACT DIVISION CHECK
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
