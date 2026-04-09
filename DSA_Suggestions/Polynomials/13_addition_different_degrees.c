/*
 * ============================================================
 * PROGRAM 13: ADDITION OF DIFFERENT DEGREES
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
