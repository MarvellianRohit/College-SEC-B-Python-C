/*
 * ============================================================
 * PROGRAM 16: QUADRATIC ROOTS
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * This program finds the roots of a quadratic equation of the 
 * form ax^2 + bx + c = 0 using the quadratic formula:
 * x = [-b ± sqrt(b^2 - 4ac)] / 2a. 
 * It also checks if the discriminant (b^2 - 4ac) is positive or 
 * negative to determine if roots are real or imaginary.
 *
 * ALGORITHM:
 * 1. START
 * 2. Define coefficients a, b, and c.
 * 3. Calculate discriminant d = (b*b) - (4*a*c).
 * 4. IF (d >= 0):
 *    a. Calculate r1 = (-b + sqrt(d)) / (2*a).
 *    b. Calculate r2 = (-b - sqrt(d)) / (2*a).
 *    c. Display r1 and r2.
 * 5. ELSE:
 *    a. Display "Roots are imaginary".
 * 6. STOP
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

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * Roots of x^2 - 5x + 6 are: 3.0, 2.0
 * ============================================================
 */
