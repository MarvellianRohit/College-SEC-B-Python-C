/*
 * ============================================================
 * PROGRAM 8: MULTIPLICATION OF HIGH-DEGREE POLYNOMIALS
 * ============================================================
 * Topic: Polynomials in Data Structures
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * Here we multiply two polynomials each of degree 3.
 * Result will have degree 3 + 3 = 6.
 *
 * Example:
 *   P1 = 2x^3 + 3x^2 - x + 4
 *   P2 = x^3  - 2x^2 + 5x - 3
 *
 * Every term of P1 multiplied by every term of P2:
 *   2x^3 * x^3  = 2x^6
 *   2x^3 * -2x^2= -4x^5
 *   2x^3 * 5x   = 10x^4
 *   2x^3 * -3   = -6x^3
 *   3x^2 * x^3  = 3x^5
 *   3x^2 * -2x^2= -6x^4
 *   ... and so on
 *
 * Collect like terms (same power) to get final answer.
 * ============================================================
 */

#include <stdio.h>

#define MAX 20   /* Result can have max degree = 3+3 = 6, so 7 terms */

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
 * Multiply poly1 (degree d1) with poly2 (degree d2).
 * result[i+j] += poly1[i] * poly2[j]  for each (i, j)
 */
int multiplyPoly(int p1[], int d1, int p2[], int d2, int result[]) {
    int i, j;
    int resultDeg = d1 + d2;    /* Degree of product = sum of degrees */

    /* Initialize result to 0 */
    for (i = 0; i <= resultDeg; i++) result[i] = 0;

    /* Nested loop: multiply each term of p1 with each term of p2 */
    for (i = 0; i <= d1; i++) {
        for (j = 0; j <= d2; j++) {
            result[i + j] += p1[i] * p2[j];
            /* Power of product = i + j (exponent rule: x^i * x^j = x^(i+j)) */
            /* Coefficient of product = p1[i] * p2[j] */
        }
    }
    return resultDeg;
}

/* ---- MAIN ---- */
int main() {
    /* P1 = 2x^3 + 3x^2 - x + 4  =>  {4, -1, 3, 2} */
    int poly1[] = {4, -1, 3, 2};
    int deg1 = 3;

    /* P2 = x^3 - 2x^2 + 5x - 3  =>  {-3, 5, -2, 1} */
    int poly2[] = {-3, 5, -2, 1};
    int deg2 = 3;

    int result[MAX];
    int degResult;

    printf("=== MULTIPLICATION OF DEGREE-3 POLYNOMIALS ===\n\n");

    printf("P1 = ");
    displayWithSign(poly1, deg1);

    printf("P2 = ");
    displayWithSign(poly2, deg2);

    /* Multiply */
    degResult = multiplyPoly(poly1, deg1, poly2, deg2, result);

    printf("\nP1 * P2 = ");
    displayWithSign(result, degResult);
    printf("(Result is a degree-%d polynomial)\n", degResult);

    /* Show the individual products step by step */
    printf("\nINDIVIDUAL PRODUCTS (before collecting like terms):\n");
    int i, j;
    for (i = deg1; i >= 0; i--) {
        for (j = deg2; j >= 0; j--) {
            int coeff = poly1[i] * poly2[j];
            int power = i + j;
            if (coeff != 0) {
                printf("  (%dx^%d) * (%dx^%d) = %dx^%d\n",
                       poly1[i], i, poly2[j], j, coeff, power);
            }
        }
    }

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === MULTIPLICATION OF DEGREE-3 POLYNOMIALS ===
 *
 * P1 = 2x^3 + 3x^2 - x + 4
 * P2 = x^3 - 2x^2 + 5x - 3
 *
 * P1 * P2 = 2x^6 - x^5 + 3x^4 - 21x^3 + 26x^2 - 17x - 12
 * (Result is a degree-6 polynomial)
 *
 * INDIVIDUAL PRODUCTS (before collecting like terms):
 *   (2x^3) * (1x^3) = 2x^6
 *   (2x^3) * (-2x^2) = -4x^5
 *   (2x^3) * (5x^1) = 10x^4
 *   (2x^3) * (-3x^0) = -6x^3
 *   (3x^2) * (1x^3) = 3x^5
 *   (3x^2) * (-2x^2) = -6x^4
 *   ... and so on
 *
 * ============================================================
 * HOW IT WORKS:
 * ============================================================
 * FOIL-like expansion for polynomials:
 * Every term in P1 is multiplied with every term in P2.
 * This uses TWO nested loops:
 *   Outer loop: i goes from 0 to deg1 (each term of P1)
 *   Inner loop: j goes from 0 to deg2 (each term of P2)
 *
 * For each pair (i, j):
 *   - New coefficient = poly1[i] * poly2[j]
 *   - New power       = i + j
 *   - Add to result[i+j]  (because multiple pairs can give same power)
 *
 * COLLECTING LIKE TERMS:
 *   result[i+j] += ...
 *   The += automatically collects terms with the same power.
 *   For example, x^4 might come from (2x^3 * 5x) and (3x^2 * -2x^2):
 *   10 + (-6) = 4  -> coefficient of x^4 is 4
 *
 * TIME COMPLEXITY: O(n*m) — two nested loops
 * SPACE COMPLEXITY: O(n+m) — result array of size (n + m + 1)
 * ============================================================
 */
