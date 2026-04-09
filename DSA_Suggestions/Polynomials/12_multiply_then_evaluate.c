/*
 * ============================================================
 * PROGRAM 12: MULTIPLY THEN EVALUATE
 * ============================================================
 */

#include <stdio.h>

int main() {
    int p1[] = {1, 1}; /* x + 1 */
    int p2[] = {2, 1}; /* x + 2 */
    int res[3] = {0};
    int x = 3;

    /* Multiply */
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res[i+j] += p1[i] * p2[j];
        }
    }

    /* Evaluate at x = 3 */
    int val = res[0] + (res[1] * x) + (res[2] * x * x);

    printf("P1*P2 eval at x=3: %d\n", val);
    return 0;
}
