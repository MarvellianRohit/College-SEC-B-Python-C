/*
 * ============================================================
 * PROGRAM 7: SUBTRACTION WITH NEGATIVE COEFFICIENTS (HARD)
 * ============================================================
 * Topic: Polynomials in Data Structures
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * Here we subtract two polynomials where the coefficients can be
 * negative numbers. The display must handle the signs properly.
 *
 * Example:
 *   P1 = 5x^5 - 3x^4 + 7x^3 - 2x^2 + 4x - 8
 *   P2 = 3x^5 + 2x^4 - 5x^3 + 6x^2 - 1x + 4
 *
 *   P1 - P2:
 *   x^5: (5 - 3)   =  2
 *   x^4: (-3 - 2)  = -5
 *   x^3: (7 - (-5))= 12
 *   x^2: (-2 - 6)  = -8
 *   x^1: (4 - (-1))=  5
 *   x^0: (-8 - 4)  = -12
 *
 *   Result = 2x^5 - 5x^4 + 12x^3 - 8x^2 + 5x - 12
 * ============================================================
 */

#include <stdio.h>

#define MAX 15

/* ---- FUNCTION: displayWithSign ----
 * Displays polynomial handling + and - signs between terms.
 * Negative coefficients print " - " between terms.
 * First term keeps its negative sign naturally.
 */
void displayWithSign(int poly[], int degree) {
    int i, first = 1;

    for (i = degree; i >= 0; i--) {
        if (poly[i] == 0) continue;   /* Skip zero terms */

        if (first) {
            /* First term: just print with its sign */
            if (i == 0)      printf("%d", poly[i]);
            else if (i == 1) printf("%dx", poly[i]);
            else             printf("%dx^%d", poly[i], i);
            first = 0;
        } else {
            /* Subsequent terms: print + or - based on sign */
            if (poly[i] > 0) {
                printf(" + ");
                if (i == 0)      printf("%d", poly[i]);
                else if (i == 1) printf("%dx", poly[i]);
                else             printf("%dx^%d", poly[i], i);
            } else {
                /* Negative: print " - " then the absolute value */
                printf(" - ");
                int absCoeff = -poly[i];   /* Make it positive for display */
                if (i == 0)      printf("%d", absCoeff);
                else if (i == 1) printf("%dx", absCoeff);
                else             printf("%dx^%d", absCoeff, i);
            }
        }
    }
    if (first) printf("0");   /* All-zero polynomial */
    printf("\n");
}

/* ---- FUNCTION: subtractPoly ---- */
int subtractPoly(int p1[], int d1, int p2[], int d2, int result[]) {
    int i;
    int maxDeg = (d1 > d2) ? d1 : d2;

    for (i = 0; i <= maxDeg; i++) result[i] = 0;

    /* Copy P1 into result */
    for (i = 0; i <= d1; i++) result[i] = p1[i];

    /* Subtract P2 from result */
    for (i = 0; i <= d2; i++) result[i] -= p2[i];

    return maxDeg;
}

/* ---- MAIN ---- */
int main() {
    /* P1 = 5x^5 - 3x^4 + 7x^3 - 2x^2 + 4x - 8 */
    int poly1[] = {-8, 4, -2, 7, -3, 5};   /* index = power, so index 5 = 5x^5 */
    int deg1 = 5;

    /* P2 = 3x^5 + 2x^4 - 5x^3 + 6x^2 - 1x + 4 */
    int poly2[] = {4, -1, 6, -5, 2, 3};
    int deg2 = 5;

    int result[MAX];
    int degResult;

    printf("=== POLYNOMIAL SUBTRACTION WITH NEGATIVE COEFFICIENTS ===\n\n");

    printf("P1 = ");
    displayWithSign(poly1, deg1);

    printf("P2 = ");
    displayWithSign(poly2, deg2);

    degResult = subtractPoly(poly1, deg1, poly2, deg2, result);

    printf("\nP1 - P2 = ");
    displayWithSign(result, degResult);

    /* Show step-by-step subtraction at each power */
    printf("\nSTEP-BY-STEP:\n");
    int i;
    for (i = deg1; i >= 0; i--) {
        int c1 = (i <= deg1) ? poly1[i] : 0;
        int c2 = (i <= deg2) ? poly2[i] : 0;
        printf("  x^%d: (%d) - (%d) = %d\n", i, c1, c2, c1 - c2);
    }

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === POLYNOMIAL SUBTRACTION WITH NEGATIVE COEFFICIENTS ===
 *
 * P1 = 5x^5 - 3x^4 + 7x^3 - 2x^2 + 4x - 8
 * P2 = 3x^5 + 2x^4 - 5x^3 + 6x^2 - 1x + 4
 *
 * P1 - P2 = 2x^5 - 5x^4 + 12x^3 - 8x^2 + 5x - 12
 *
 * STEP-BY-STEP:
 *   x^5: (5) - (3) = 2
 *   x^4: (-3) - (2) = -5
 *   x^3: (7) - (-5) = 12
 *   x^2: (-2) - (6) = -8
 *   x^1: (4) - (-1) = 5
 *   x^0: (-8) - (4) = -12
 *
 * ============================================================
 * HOW IT WORKS:
 * ============================================================
 * The key here is handling NEGATIVE COEFFICIENTS in two places:
 *
 * 1. IN STORAGE: We simply store negative values in the array.
 *    e.g., -3x^4 is stored as poly[4] = -3
 *    Arrays in C can hold negative integers, so no special handling needed.
 *
 * 2. IN DISPLAY: We check if poly[i] > 0 or < 0:
 *    - If positive -> print " + " before the coefficient
 *    - If negative -> print " - " and then the ABSOLUTE VALUE
 *    This makes the output look like proper mathematics.
 *
 * 3. IN SUBTRACTION: Subtracting a negative = adding!
 *    (7) - (-5) = 7 + 5 = 12
 *    This is why the coefficient of x^3 jumps from 7 to 12.
 *
 * This program helps understand:
 * - How to work with signed integers in arrays
 * - How display logic must handle both positive and negative terms
 * ============================================================
 */
