/*
 * ============================================================
 * PROGRAM 02: POLYNOMIAL SUBTRACTION
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * This program performs polynomial subtraction. It works by 
 * taking two polynomials stored in arrays and subtracting the 
 * coefficients of matching powers (indices). 
 * Resulting Coefficient = P1 Coefficient - P2 Coefficient.
 *
 * ALGORITHM:
 * 1. START
 * 2. Input the degree and coefficients for P1 and P2.
 * 3. Find the higher degree (maxDeg).
 * 4. Loop from i = 0 to maxDeg:
 *    a. Result[i] = P1[i] - P2[i].
 * 5. Display the subtracted polynomial.
 * 6. STOP
 * ============================================================
 */

#include <stdio.h>

#define MAX 10

void readPoly(int poly[], int degree) {
    for (int i = 0; i <= degree; i++) {
        printf("  Enter coefficient for x^%d: ", i);
        scanf("%d", &poly[i]);
    }
}

void displayPoly(int poly[], int degree) {
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            printf("%dx^%d ", poly[i], i);
            if (i > 0) printf("+ ");
        }
    }
    printf("\n");
}

int subtractPoly(int p1[], int d1, int p2[], int d2, int result[]) {
    int maxDeg = (d1 > d2) ? d1 : d2;

    for (int i = 0; i <= maxDeg; i++) result[i] = 0;

    for (int i = 0; i <= d1; i++) result[i] += p1[i];
    for (int i = 0; i <= d2; i++) result[i] -= p2[i];

    return maxDeg;
}

int main() {
    int p1[MAX], p2[MAX], diff[MAX];
    int deg1, deg2, degDiff;

    printf("=== POLYNOMIAL SUBTRACTION ===\n\n");

    printf("First Polynomial Degree: "); scanf("%d", &deg1);
    readPoly(p1, deg1);

    printf("\nSecond Polynomial Degree: "); scanf("%d", &deg2);
    readPoly(p2, deg2);

    degDiff = subtractPoly(p1, deg1, p2, deg2, diff);

    printf("\nFirst:  "); displayPoly(p1, deg1);
    printf("Second: "); displayPoly(p2, deg2);
    printf("Diff:   "); displayPoly(diff, degDiff);

    return 0;
}

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * === POLYNOMIAL SUBTRACTION ===
 *
 * First Polynomial:
 * Enter degree: 2
 *   Enter coefficient for x^0: 5
 *   Enter coefficient for x^1: 10
 *   Enter coefficient for x^2: 3
 *
 * Second Polynomial:
 * Enter degree: 2
 *   Enter coefficient for x^0: 2
 *   Enter coefficient for x^1: 4
 *   Enter coefficient for x^2: 1
 *
 * First:  3x^2 + 10x^1 + 5x^0 
 * Second: 1x^2 + 4x^1 + 2x^0 
 * Result: 2x^2 + 6x^1 + 3x^0 
 * ============================================================
 */
