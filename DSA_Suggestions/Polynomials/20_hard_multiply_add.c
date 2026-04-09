/*
 * ============================================================
 * PROGRAM 20: HARD MULTIPLY AND ADD: (P1*P2) + (P1*P3)
 * ============================================================
 */

#include <stdio.h>

int main() {
    int p1[] = {1, 1}; /* x + 1 */
    int p2[] = {2, 1}; /* x + 2 */
    int p3[] = {3, 1}; /* x + 3 */

    int prod1[3] = {0}, prod2[3] = {0}, res[3];

    /* P1 * P2 */
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            prod1[i+j] += p1[i] * p2[j];

    /* P1 * P3 */
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            prod2[i+j] += p1[i] * p3[j];

    /* (P1*P2) + (P1*P3) */
    for (int i = 0; i < 3; i++) res[i] = prod1[i] + prod2[i];

    printf("Final Hard Result:\n");
    for (int i = 2; i >= 0; i--) printf("%dx^%d ", res[i], i);
    printf("\n");

    return 0;
}
