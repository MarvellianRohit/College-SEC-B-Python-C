/*
 * ============================================================
 * PROGRAM 6: ADDITION OF THREE POLYNOMIALS (HIGH DEGREE)
 * ============================================================
 * Topic: Polynomials in Data Structures
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * We add THREE polynomials together.
 * First add poly1 + poly2 = temp
 * Then add temp + poly3 = final result
 *
 * Example (harder, degree 4):
 *   P1 = 4x^4 + 3x^3 + 2x^2 + 5x + 6
 *   P2 = 2x^4 + 0x^3 + 7x^2 + 3x + 1
 *   P3 = 1x^4 + 5x^3 + 0x^2 + 2x + 9
 *
 *   P1+P2+P3 = 7x^4 + 8x^3 + 9x^2 + 10x + 16
 * ============================================================
 */

#include <stdio.h>

#define MAX 15   /* Support up to degree 14 */

/* ---- FUNCTION: addTwo ----
 * Adds two polynomials and stores result in out[].
 * Returns the degree of the result.
 */
int addTwo(int p1[], int d1, int p2[], int d2, int out[]) {
    int i;
    int maxDeg = (d1 > d2) ? d1 : d2;   /* Highest of the two degrees */

    for (i = 0; i <= maxDeg; i++) out[i] = 0;   /* Clear result */

    for (i = 0; i <= d1; i++) out[i] += p1[i];  /* Add poly1 */
    for (i = 0; i <= d2; i++) out[i] += p2[i];  /* Add poly2 */

    return maxDeg;
}

/* ---- FUNCTION: display ---- */
void display(int poly[], int degree) {
    int i, first = 1;
    for (i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            if (!first) printf(" + ");
            if (i == 0)      printf("%d", poly[i]);
            else if (i == 1) printf("%dx", poly[i]);
            else             printf("%dx^%d", poly[i], i);
            first = 0;
        }
    }
    printf("\n");
}

/* ---- MAIN ---- */
int main() {
    /* Hard-coded high-degree polynomials for demonstration */

    /* P1 = 4x^4 + 3x^3 + 2x^2 + 5x + 6 */
    int poly1[] = {6, 5, 2, 3, 4};   /* index = power */
    int deg1 = 4;

    /* P2 = 2x^4 + 0x^3 + 7x^2 + 3x + 1 */
    int poly2[] = {1, 3, 7, 0, 2};
    int deg2 = 4;

    /* P3 = 1x^4 + 5x^3 + 0x^2 + 2x + 9 */
    int poly3[] = {9, 2, 0, 5, 1};
    int deg3 = 4;

    int temp[MAX], result[MAX];
    int degTemp, degResult;

    printf("=== ADDITION OF THREE POLYNOMIALS (Degree 4) ===\n\n");

    printf("P1 = "); display(poly1, deg1);
    printf("P2 = "); display(poly2, deg2);
    printf("P3 = "); display(poly3, deg3);

    /* Step 1: Add P1 + P2 = temp */
    degTemp = addTwo(poly1, deg1, poly2, deg2, temp);
    printf("\nStep 1: P1 + P2 = "); display(temp, degTemp);

    /* Step 2: Add temp + P3 = result */
    degResult = addTwo(temp, degTemp, poly3, deg3, result);
    printf("Step 2: (P1+P2) + P3 = "); display(result, degResult);

    printf("\nFinal Answer: P1 + P2 + P3 = ");
    display(result, degResult);

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === ADDITION OF THREE POLYNOMIALS (Degree 4) ===
 *
 * P1 = 4x^4 + 3x^3 + 2x^2 + 5x + 6
 * P2 = 2x^4 + 7x^2 + 3x + 1
 * P3 = 1x^4 + 5x^3 + 2x + 9
 *
 * Step 1: P1 + P2 = 6x^4 + 3x^3 + 9x^2 + 8x + 7
 * Step 2: (P1+P2) + P3 = 7x^4 + 8x^3 + 9x^2 + 10x + 16
 *
 * Final Answer: P1 + P2 + P3 = 7x^4 + 8x^3 + 9x^2 + 10x + 16
 *
 * ============================================================
 * HOW IT WORKS:
 * ============================================================
 * To add 3 polynomials, we break it into 2 steps:
 *   Step 1: result = P1 + P2  (standard coefficient-wise addition)
 *   Step 2: result = result + P3
 *
 * At each index i:
 *   result[i] = poly1[i] + poly2[i] + poly3[i]
 *
 * WHY STORE SEPARATELY?
 *   We use a temporary array so P1 and P2 are not modified.
 *   This is good practice - never destroy input data.
 *
 * MISSING TERMS (like 0x^3 in P2):
 *   Since the array is initialized to 0, missing terms automatically
 *   contribute 0 to the sum. This is why the array approach is powerful.
 *
 * TIME COMPLEXITY: O(n) — we do two passes, each O(n)
 * SPACE COMPLEXITY: O(n) — one temp array + one result array
 * ============================================================
 */
