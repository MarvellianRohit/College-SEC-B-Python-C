/*
 * ============================================================
 * PROGRAM 14: ADDITION THEN MULTIPLY
 * ============================================================
 */

#include <stdio.h>

int main() {
    int p1[] = {1, 1}; /* x + 1 */
    int p2[] = {2, 1}; /* x + 2 */
    int p3[] = {1, 1}; /* x + 1 */
    int sum[2], res[3] = {0};

    /* sum = P1 + P2 */
    for (int i = 0; i < 2; i++) sum[i] = p1[i] + p2[i];

    /* res = sum * P3 */
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res[i+j] += sum[i] * p3[j];
        }
    }

    printf("Result of (P1+P2)*P3:\n");
    for (int i = 2; i >= 0; i--) printf("%dx^%d ", res[i], i);
    printf("\n");

    return 0;
}
