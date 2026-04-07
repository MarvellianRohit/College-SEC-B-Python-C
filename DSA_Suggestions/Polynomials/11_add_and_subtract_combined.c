/*
 * ============================================================
 * PROGRAM 11: ADD TWO POLYNOMIALS THEN SUBTRACT A THIRD
 * ============================================================
 * Topic: Polynomials in Data Structures
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * This program combines both addition and subtraction:
 *   Result = (P1 + P2) - P3
 *
 * We use harder polynomials with degree 5 to practice.
 *
 * Example:
 *   P1 = 6x^5 + 4x^4 - 3x^3 + 2x^2 + x + 10
 *   P2 = 2x^5 - x^4  + 5x^3 + 0x^2 - 3x + 4
 *   P3 = x^5  + 3x^4 + 2x^3 - x^2  + 7x + 1
 *
 *   P1 + P2 = 8x^5 + 3x^4 + 2x^3 + 2x^2 - 2x + 14
 *   (P1+P2) - P3 = 7x^5 + 0x^4 + 0x^3 + 3x^2 - 9x + 13
 *              = 7x^5 + 3x^2 - 9x + 13
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

/* ---- FUNCTION: addPoly ---- Returns max degree */
int addPoly(int p1[], int d1, int p2[], int d2, int out[]) {
    int i;
    int maxD = (d1 > d2) ? d1 : d2;
    for (i = 0; i <= maxD; i++) out[i] = 0;
    for (i = 0; i <= d1; i++) out[i] += p1[i];
    for (i = 0; i <= d2; i++) out[i] += p2[i];
    return maxD;
}

/* ---- FUNCTION: subtractPoly ---- Returns max degree */
int subtractPoly(int p1[], int d1, int p2[], int d2, int out[]) {
    int i;
    int maxD = (d1 > d2) ? d1 : d2;
    for (i = 0; i <= maxD; i++) out[i] = 0;
    for (i = 0; i <= d1; i++) out[i] = p1[i];
    for (i = 0; i <= d2; i++) out[i] -= p2[i];
    return maxD;
}

/* ---- MAIN ---- */
int main() {
    /* P1 = 6x^5 + 4x^4 - 3x^3 + 2x^2 + x + 10
     * Array index = power: {10, 1, 2, -3, 4, 6} */
    int poly1[] = {10, 1, 2, -3, 4, 6};
    int deg1 = 5;

    /* P2 = 2x^5 - x^4 + 5x^3 + 0x^2 - 3x + 4
     * Array: {4, -3, 0, 5, -1, 2} */
    int poly2[] = {4, -3, 0, 5, -1, 2};
    int deg2 = 5;

    /* P3 = x^5 + 3x^4 + 2x^3 - x^2 + 7x + 1
     * Array: {1, 7, -1, 2, 3, 1} */
    int poly3[] = {1, 7, -1, 2, 3, 1};
    int deg3 = 5;

    int temp[MAX], result[MAX];
    int degTemp, degResult;

    printf("=== COMBINED OPERATION: (P1 + P2) - P3 ===\n\n");

    printf("P1 = "); displayWithSign(poly1, deg1);
    printf("P2 = "); displayWithSign(poly2, deg2);
    printf("P3 = "); displayWithSign(poly3, deg3);

    /* Step 1: temp = P1 + P2 */
    degTemp = addPoly(poly1, deg1, poly2, deg2, temp);
    printf("\nStep 1: P1 + P2 = ");
    displayWithSign(temp, degTemp);

    /* Step 2: result = temp - P3 */
    degResult = subtractPoly(temp, degTemp, poly3, deg3, result);
    printf("Step 2: (P1+P2) - P3 = ");
    displayWithSign(result, degResult);

    /* Show term-by-term calculation */
    printf("\nTERM-BY-TERM CALCULATION:\n");
    printf("%-5s | %-8s | %-8s | %-10s | %-10s | %-10s\n",
           "Power", "P1", "P2", "P1+P2", "P3", "(P1+P2)-P3");
    printf("------------------------------------------------------------\n");
    int i;
    for (i = 5; i >= 0; i--) {
        int c1 = poly1[i], c2 = poly2[i], c3 = poly3[i];
        printf("  x^%d | %-8d | %-8d | %-10d | %-10d | %-10d\n",
               i, c1, c2, c1+c2, c3, c1+c2-c3);
    }

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === COMBINED OPERATION: (P1 + P2) - P3 ===
 *
 * P1 = 6x^5 + 4x^4 - 3x^3 + 2x^2 + x + 10
 * P2 = 2x^5 - x^4 + 5x^3 - 3x + 4
 * P3 = x^5 + 3x^4 + 2x^3 - x^2 + 7x + 1
 *
 * Step 1: P1 + P2 = 8x^5 + 3x^4 + 2x^3 + 2x^2 - 2x + 14
 * Step 2: (P1+P2) - P3 = 7x^5 + 3x^2 - 9x + 13
 *
 * TERM-BY-TERM CALCULATION:
 * Power | P1       | P2       | P1+P2     | P3         | (P1+P2)-P3
 * ------------------------------------------------------------
 *   x^5 | 6        | 2        | 8          | 1          | 7
 *   x^4 | 4        | -1       | 3          | 3          | 0
 *   x^3 | -3       | 5        | 2          | 2          | 0
 *   x^2 | 2        | 0        | 2          | -1         | 3
 *   x^1 | 1        | -3       | -2         | 7          | -9
 *   x^0 | 10       | 4        | 14         | 1          | 13
 *
 * ============================================================
 * HOW IT WORKS:
 * ============================================================
 * This program demonstrates CHAINING of operations:
 *   1. Compute temp = P1 + P2  (using addPoly)
 *   2. Compute result = temp - P3  (using subtractPoly)
 *
 * The TABLE shows clearly:
 *   - Column by column, how each power's coefficient changes
 *   - Addition adds corresponding terms
 *   - Subtraction subtracts corresponding terms
 *   - Terms that cancel out (like x^4 = 3 - 3 = 0) disappear from display
 *
 * The result 7x^5 + 3x^2 - 9x + 13 shows that x^4 and x^3 terms
 * cancelled out completely — an important concept in polynomial arithmetic.
 * ============================================================
 */
