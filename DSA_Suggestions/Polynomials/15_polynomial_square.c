/*
 * ============================================================
 * PROGRAM 15: POLYNOMIAL SQUARE (P1 * P1)
 * ============================================================
 */

#include <stdio.h>

int main() {
    int p1[] = {3, 1}; /* x + 3 */
    int res[3] = {0};

    /* P1 * P1 */
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res[i+j] += p1[i] * p1[j];
        }
    }

    printf("Square of (x + 3):\n");
    for (int i = 2; i >= 0; i--) printf("%dx^%d ", res[i], i);
    printf("\n");

    return 0;
}
