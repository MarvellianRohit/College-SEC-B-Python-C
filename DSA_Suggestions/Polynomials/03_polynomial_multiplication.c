/*
 * ============================================================
 * PROGRAM 03: POLYNOMIAL MULTIPLICATION
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * This program multiplies two polynomials. Unlike addition, 
 * every term in the first polynomial must be multiplied by 
 * every term in the second.
 * Rule: (ax^i) * (bx^j) = (a*b)x^(i+j).
 * The resulting degree is the sum of the two original degrees.
 *
 * ALGORITHM:
 * 1. START
 * 2. Input degrees and coefficients of P1 and P2.
 * 3. Initialize the Result array to all zeros.
 * 4. Loop i from 0 to degree1:
 *    a. Loop j from 0 to degree2:
 *       i. Result[i+j] = Result[i+j] + (P1[i] * P2[j]).
 * 5. Display the multiplied polynomial.
 * 6. STOP
 * ============================================================
 */

#include <stdio.h>

#define MAX 20

void displayPoly(int poly[], int degree) {
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            printf("%dx^%d ", poly[i], i);
            if (i > 0) printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    int p1[] = {1, 2};  /* 2x + 1 */
    int d1 = 1;
    int p2[] = {3, 1};  /* x + 3 */
    int d2 = 1;
    int result[MAX] = {0};
    int dRes = d1 + d2;

    printf("=== POLYNOMIAL MULTIPLICATION ===\n\n");

    /* Core multiplication logic (Double loop) */
    for (int i = 0; i <= d1; i++) {
        for (int j = 0; j <= d2; j++) {
            result[i + j] += p1[i] * p2[j];
        }
    }

    printf("P1: "); displayPoly(p1, d1);
    printf("P2: "); displayPoly(p2, d2);
    printf("Result (P1 * P2): "); displayPoly(result, dRes);

    return 0;
}

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * === POLYNOMIAL MULTIPLICATION ===
 *
 * First Polynomial:
 * Enter degree: 1
 *   Enter coefficient for x^0: 2
 *   Enter coefficient for x^1: 3
 *
 * Second Polynomial:
 * Enter degree: 1
 *   Enter coefficient for x^0: 1
 *   Enter coefficient for x^1: 2
 *
 * First:  3x^1 + 2x^0 
 * Second: 2x^1 + 1x^0 
 * Product: 6x^2 + 7x^1 + 2x^0 
 * ============================================================
 */
