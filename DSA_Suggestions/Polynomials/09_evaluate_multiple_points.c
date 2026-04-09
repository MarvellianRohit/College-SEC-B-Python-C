/*
 * ============================================================
 * PROGRAM 09: EVALUATE AT MULTIPLE POINTS
 * ============================================================
 */

#include <stdio.h>
#include <math.h>

int main() {
    int poly[] = {1, 2, 1}; /* x^2 + 2x + 1 */
    float points[] = {0, 1, 2, -1};

    printf("Evaluation of x^2 + 2x + 1:\n");
    for (int i = 0; i < 4; i++) {
        float x = points[i];
        float val = (x*x) + (2*x) + 1;
        printf("  P(%.1f) = %.2f\n", x, val);
    }

    return 0;
}
