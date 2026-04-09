/*
 * ============================================================
 * PROGRAM 02: POLYNOMIAL SUBTRACTION
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * Subtraction is just like addition, but we subtract the 
 * coefficients at each index: result[i] = p1[i] - p2[i]
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
