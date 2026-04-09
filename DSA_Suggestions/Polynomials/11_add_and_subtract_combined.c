/*
 * ============================================================
 * PROGRAM 11: ADD AND SUBTRACT COMBINED
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
