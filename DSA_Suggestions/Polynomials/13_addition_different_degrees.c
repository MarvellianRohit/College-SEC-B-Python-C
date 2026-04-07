/*
 * ============================================================
 * PROGRAM 13: POLYNOMIAL ADDITION WITH DIFFERENT DEGREES
 * ============================================================
 * Topic: Polynomials in Data Structures
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * Adding two polynomials where one has a much higher degree
 * than the other. The extra terms of the higher-degree polynomial
 * simply carry over unchanged.
 *
 * Example (harder case):
 *   P1 (degree 6) = 5x^6 + 3x^5 - 4x^4 + 2x^3 + 7x + 9
 *   P2 (degree 2) = 6x^2 - 5x  + 11
 *
 *   Result:
 *   x^6: 5 (only in P1)
 *   x^5: 3 (only in P1)
 *   x^4: -4 (only in P1)
 *   x^3: 2 (only in P1)
 *   x^2: 0+6 = 6  (only in P2)
 *   x^1: 7+(-5) = 2
 *   x^0: 9+11 = 20
 * ============================================================
 */

#include <stdio.h>

#define MAX 15

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

/* ---- FUNCTION: addPoly ---- */
int addPoly(int p1[], int d1, int p2[], int d2, int out[]) {
    int i;
    int maxD = (d1 > d2) ? d1 : d2;
    for (i = 0; i <= maxD; i++) out[i] = 0;
    for (i = 0; i <= d1; i++) out[i] += p1[i];
    for (i = 0; i <= d2; i++) out[i] += p2[i];
    return maxD;
}

/* ---- MAIN ---- */
int main() {
    /* P1 = 5x^6 + 3x^5 - 4x^4 + 2x^3 + 0x^2 + 7x + 9
     * Array (index=power): {9, 7, 0, 2, -4, 3, 5} */
    int poly1[] = {9, 7, 0, 2, -4, 3, 5};
    int deg1 = 6;

    /* P2 = 6x^2 - 5x + 11
     * Array: {11, -5, 6} */
    int poly2[] = {11, -5, 6};
    int deg2 = 2;

    int result[MAX];
    int degResult;

    printf("=== ADDING POLYNOMIALS OF DIFFERENT DEGREES ===\n\n");

    printf("P1 (degree %d) = ", deg1); displayWithSign(poly1, deg1);
    printf("P2 (degree %d) = ", deg2); displayWithSign(poly2, deg2);

    degResult = addPoly(poly1, deg1, poly2, deg2, result);

    printf("\nP1 + P2 = ");
    displayWithSign(result, degResult);

    /* Show which terms are shared, unique to P1, or unique to P2 */
    printf("\nTERM ANALYSIS:\n");
    printf("%-5s | %-10s | %-10s | %-10s | %-10s\n",
           "x^n ", "P1 coeff", "P2 coeff", "Sum", "Origin");
    printf("-------------------------------------------------------\n");

    int i;
    for (i = degResult; i >= 0; i--) {
        int c1 = (i <= deg1) ? poly1[i] : 0;
        int c2 = (i <= deg2) ? poly2[i] : 0;
        char *origin;

        if (i > deg2)      origin = "P1 only";
        else if (i > deg1) origin = "P2 only";
        else               origin = "Both";

        if (c1 != 0 || c2 != 0) {   /* Skip if both are zero */
            printf("  x^%d | %-10d | %-10d | %-10d | %s\n",
                   i, c1, c2, c1 + c2, origin);
        }
    }

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === ADDING POLYNOMIALS OF DIFFERENT DEGREES ===
 *
 * P1 (degree 6) = 5x^6 + 3x^5 - 4x^4 + 2x^3 + 7x + 9
 * P2 (degree 2) = 6x^2 - 5x + 11
 *
 * P1 + P2 = 5x^6 + 3x^5 - 4x^4 + 2x^3 + 6x^2 + 2x + 20
 *
 * TERM ANALYSIS:
 * x^n  | P1 coeff  | P2 coeff  | Sum        | Origin
 * -------------------------------------------------------
 *   x^6 | 5          | 0          | 5          | P1 only
 *   x^5 | 3          | 0          | 3          | P1 only
 *   x^4 | -4         | 0          | -4         | P1 only
 *   x^3 | 2          | 0          | 2          | P1 only
 *   x^2 | 0          | 6          | 6          | Both
 *   x^1 | 7          | -5         | 2          | Both
 *   x^0 | 9          | 11         | 20         | Both
 *
 * ============================================================
 * HOW IT WORKS:
 * ============================================================
 * KEY INSIGHT: When degrees are different, higher-degree terms
 * from the larger polynomial simply carry into the result unchanged.
 * This happens automatically because:
 *   - We initialize result[] to 0
 *   - We add P1 terms into result (high-degree terms go in as-is)
 *   - We add P2 terms into result (only lower-degree terms exist)
 *   - Terms only present in P1 stay unchanged in result
 *   - Terms only present in P2 are added to result's 0 values
 *   - Overlapping terms (x^1 and x^0) are summed normally
 *
 * This is exactly what would happen in math:
 *   There is no x^6 term in P2, so result x^6 = P1's x^6 + 0 = unchanged
 * ============================================================
 */
