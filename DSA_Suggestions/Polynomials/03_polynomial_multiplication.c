/*
 * ============================================================
 * PROGRAM 03: POLYNOMIAL MULTIPLICATION
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * Multiplication is slightly harder. 
 * If we multiply p1[i] and p2[j], the result is stored 
 * at result[i + j].
 * ============================================================
 */

#include <stdio.h>

#define MAX 20

void displayPoly(int poly[], int degree) {
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            printf("%dx^%d ", poly[i], i);
            if (i > 0) printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    int p1[] = {1, 2};  /* 2x + 1 */
    int d1 = 1;
    int p2[] = {3, 1};  /* x + 3 */
    int d2 = 1;
    int result[MAX] = {0};
    int dRes = d1 + d2;

    printf("=== POLYNOMIAL MULTIPLICATION ===\n\n");

    /* Core multiplication logic (Double loop) */
    for (int i = 0; i <= d1; i++) {
        for (int j = 0; j <= d2; j++) {
            result[i + j] += p1[i] * p2[j];
        }
    }

    printf("P1: "); displayPoly(p1, d1);
    printf("P2: "); displayPoly(p2, d2);
    printf("Result (P1 * P2): "); displayPoly(result, dRes);

    return 0;
}
