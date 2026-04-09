/*
 * ============================================================
 * PROGRAM 16: QUADRATIC ROOTS
 * ============================================================
 */

#include <stdio.h>
#include <math.h>

int main() {
    /* ax^2 + bx + c = 0 */
    float a = 1, b = -5, c = 6;
    float d = (b*b) - (4*a*c);

    if (d >= 0) {
        float r1 = (-b + sqrt(d)) / (2*a);
        float r2 = (-b - sqrt(d)) / (2*a);
        printf("Roots of x^2 - 5x + 6 are: %.1f, %.1f\n", r1, r2);
    } else {
        printf("Roots are imaginary.\n");
    }

    return 0;
}
