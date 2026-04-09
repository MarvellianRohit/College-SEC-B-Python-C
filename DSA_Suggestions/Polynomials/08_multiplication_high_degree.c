/*
 * ============================================================
 * PROGRAM 08: MULTIPLICATION OF HIGH DEGREE POLYNOMIALS
 * ============================================================
 */

#include <stdio.h>

#define MAX 50

int main() {
    int p1[] = {1, 2, 3, 4}; /* 4x^3 + 3x^2 + 2x + 1 */
    int p2[] = {5, 6, 7};    /* 7x^2 + 6x + 5 */
    int res[MAX] = {0};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            res[i+j] += p1[i] * p2[j];
        }
    }

    printf("Large Multiplication Result:\n  ");
    for (int i = 5; i >= 0; i--) {
        if (res[i] != 0) printf("%dx^%d + ", res[i], i);
    }
    printf("0\n");

    return 0;
}
