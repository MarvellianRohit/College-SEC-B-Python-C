/*
 * ============================================================
 * PROGRAM 17: SUBTRACTION THEN EVALUATE
 * ============================================================
 */

#include <stdio.h>

int main() {
    int p1[] = {10, 5}; /* 5x + 10 */
    int p2[] = {4, 2};  /* 2x + 4 */
    int diff[2];
    int x = 2;

    for (int i = 0; i < 2; i++) diff[i] = p1[i] - p2[i];

    int val = diff[0] + (diff[1] * x);

    printf("(P1-P2) evaluated at x=2: %d\n", val);
    return 0;
}
