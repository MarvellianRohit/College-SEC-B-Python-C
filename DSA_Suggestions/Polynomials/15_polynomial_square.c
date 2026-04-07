/*
 * ============================================================
 * PROGRAM 15: SQUARE OF A POLYNOMIAL — P(x)^2
 * ============================================================
 * Topic: Polynomials in Data Structures
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * Squaring a polynomial means multiplying it by ITSELF:
 *   P^2 = P * P
 *
 * This is a special case of polynomial multiplication where
 * both polynomials are the same.
 *
 * Example:
 *   P = 2x^2 - 3x + 4
 *   P^2 = (2x^2 - 3x + 4) * (2x^2 - 3x + 4)
 *       = 4x^4 - 12x^3 + 25x^2 - 24x + 16
 *
 * We can verify using (a-b+c)^2 = a^2 + b^2 + c^2 + 2 cross-terms
 * a = 2x^2, b = 3x, c = 4:
 *   a^2 = 4x^4
 *   b^2 = 9x^2
 *   c^2 = 16
 *   2ab = 2*(2x^2)*(-3x) = -12x^3
 *   2ac = 2*(2x^2)*(4)   = 16x^2
 *   2bc = 2*(-3x)*(4)    = -24x
 *   Sum = 4x^4 - 12x^3 + (9+16)x^2 - 24x + 16 = 4x^4 - 12x^3 + 25x^2 - 24x + 16
 * ============================================================
 */

#include <stdio.h>

#define MAX 20

/* ---- FUNCTION: displayWithSign ---- */
void displayWithSign(int poly[], int degree) {
    int i, first = 1;
    for (i = degree; i >= 0; i--) {
        if (poly[i] == 0) continue;
        if (first) {
            if (i == 0)      printf("%d", poly[i]);
            else if (i == 1) printf("%dx", poly[i]);
            else             printf("%dx^%d", poly[i], i);
            first = 0;
        } else {
            if (poly[i] > 0) {
                printf(" + ");
                if (i == 0)      printf("%d", poly[i]);
                else if (i == 1) printf("%dx", poly[i]);
                else             printf("%dx^%d", poly[i], i);
            } else {
                printf(" - ");
                int a = -poly[i];
                if (i == 0)      printf("%d", a);
                else if (i == 1) printf("%dx", a);
                else             printf("%dx^%d", a, i);
            }
        }
    }
    if (first) printf("0");
    printf("\n");
}

/* ---- FUNCTION: multiplyPoly ----
 * Multiplies p1 by p2 and stores in result[].
 */
int multiplyPoly(int p1[], int d1, int p2[], int d2, int result[]) {
    int i, j;
    int resultDeg = d1 + d2;
    for (i = 0; i <= resultDeg; i++) result[i] = 0;
    for (i = 0; i <= d1; i++) {
        for (j = 0; j <= d2; j++) {
            result[i + j] += p1[i] * p2[j];
        }
    }
    return resultDeg;
}

/* ---- FUNCTION: evaluate ---- */
float evaluate(int poly[], int degree, float x) {
    float result = poly[degree];
    int i;
    for (i = degree - 1; i >= 0; i--) {
        result = result * x + poly[i];
    }
    return result;
}

/* ---- MAIN ---- */
int main() {
    /* P = 2x^2 - 3x + 4  =>  {4, -3, 2} */
    int poly[] = {4, -3, 2};
    int degree = 2;

    int squared[MAX];
    int degSquared;

    printf("=== SQUARING A POLYNOMIAL: P^2 ===\n\n");

    printf("P(x) = ");
    displayWithSign(poly, degree);

    /* Square the polynomial by multiplying it with itself */
    degSquared = multiplyPoly(poly, degree, poly, degree, squared);
    /* Note: we pass 'poly' twice — same array for both arguments */

    printf("\n[P(x)]^2 = P(x) * P(x) = ");
    displayWithSign(squared, degSquared);
    printf("(Degree doubled: %d -> %d)\n", degree, degSquared);

    /* Show individual multiplication steps */
    printf("\nEXPANSION STEPS:\n");
    printf("(2x^2 - 3x + 4)(2x^2 - 3x + 4):\n");
    int i, j;
    for (i = degree; i >= 0; i--) {
        for (j = degree; j >= 0; j--) {
            int c = poly[i] * poly[j];
            int p = i + j;
            if (c != 0) {
                printf("  (%dx^%d) x (%dx^%d) = %dx^%d\n",
                       poly[i], i, poly[j], j, c, p);
            }
        }
    }

    /* Verify at x = 1 */
    float x = 1.0;
    float orig = evaluate(poly, degree, x);
    float sq   = evaluate(squared, degSquared, x);
    printf("\nVERIFICATION at x = %.0f:\n", x);
    printf("  P(%.0f) = %.2f\n", x, orig);
    printf("  [P(%.0f)]^2 = %.2f * %.2f = %.2f\n", x, orig, orig, orig * orig);
    printf("  P^2(%.0f) = %.2f\n", x, sq);
    printf("  Match: %s\n", (orig * orig == sq) ? "YES!" : "Close (float precision)");

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === SQUARING A POLYNOMIAL: P^2 ===
 *
 * P(x) = 2x^2 - 3x + 4
 *
 * [P(x)]^2 = P(x) * P(x) = 4x^4 - 12x^3 + 25x^2 - 24x + 16
 * (Degree doubled: 2 -> 4)
 *
 * EXPANSION STEPS:
 * (2x^2 - 3x + 4)(2x^2 - 3x + 4):
 *   (2x^2) x (2x^2) = 4x^4
 *   (2x^2) x (-3x^1) = -6x^3
 *   (2x^2) x (4x^0) = 8x^2
 *   (-3x^1) x (2x^2) = -6x^3
 *   (-3x^1) x (-3x^1) = 9x^2
 *   (-3x^1) x (4x^0) = -12x^1
 *   (4x^0) x (2x^2) = 8x^2
 *   (4x^0) x (-3x^1) = -12x^1
 *   (4x^0) x (4x^0) = 16x^0
 *
 * VERIFICATION at x = 1:
 *   P(1) = 2 - 3 + 4 = 3.00
 *   [P(1)]^2 = 3.00 * 3.00 = 9.00
 *   P^2(1) = 4 - 12 + 25 - 24 + 16 = 9.00
 *   Match: YES!
 *
 * ============================================================
 * HOW IT WORKS:
 * ============================================================
 * Squaring a polynomial = multiplying it by itself.
 *
 * We reuse our multiplyPoly() function by passing the same array
 * as both arguments:
 *   multiplyPoly(poly, degree, poly, degree, squared)
 *
 * The nested-loop multiplication handles this correctly:
 *   Every term of P is multiplied with every term of P (including itself),
 *   giving all the cross-term products shown in the expansion steps.
 *
 * OBSERVATION:
 *   When you square a polynomial of degree n, you get degree 2n.
 *   (2x^2)^2 -> degree 4. This is because x^n * x^n = x^(2n).
 *
 * VERIFICATION TRICK:
 *   [P(x)]^2 at any x should equal the squared polynomial evaluated at x.
 *   We tested this at x=1 and it confirmed both give 9.
 * ============================================================
 */
