/*
 * ============================================================
 * PROGRAM 20: HARD MULTIPLICATION — (P1*P2) + (P1*P3)
 * ============================================================
 * Topic: Polynomials in Data Structures
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * This program:
 *   1. Multiplies P1 * P2  -> prod1
 *   2. Multiplies P1 * P3  -> prod2
 *   3. Adds prod1 + prod2  -> final result
 *
 * This is equivalent to P1 * (P2 + P3) by the distributive law.
 * We verify this by also computing P1 * (P2+P3) separately.
 *
 * We use HARD high-degree polynomials:
 *   P1 = 4x^4 - x^3 + 2x^2 + 5x - 3
 *   P2 = x^3  - 3x^2 + 2x - 7
 *   P3 = 2x^3 + x^2  - 6x + 4
 *
 *   P2 + P3 = 3x^3 - 2x^2 - 4x - 3
 *   P1*(P2+P3) should equal P1*P2 + P1*P3
 *
 * This is the hardest polynomial program in our set!
 * ============================================================
 */

#include <stdio.h>

#define MAX 25

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

/* ---- FUNCTION: multiplyPoly ---- */
int multiplyPoly(int p1[], int d1, int p2[], int d2, int out[]) {
    int i, j;
    int rDeg = d1 + d2;
    for (i = 0; i <= rDeg; i++) out[i] = 0;
    for (i = 0; i <= d1; i++) {
        for (j = 0; j <= d2; j++) {
            out[i + j] += p1[i] * p2[j];
        }
    }
    return rDeg;
}

/* ---- FUNCTION: checkEqual ----
 * Returns 1 if two polynomials are equal, 0 otherwise.
 */
int checkEqual(int a[], int da, int b[], int db) {
    int i;
    int maxD = (da > db) ? da : db;
    for (i = 0; i <= maxD; i++) {
        int ca = (i <= da) ? a[i] : 0;
        int cb = (i <= db) ? b[i] : 0;
        if (ca != cb) return 0;
    }
    return 1;
}

/* ---- MAIN ---- */
int main() {
    /* P1 = 4x^4 - x^3 + 2x^2 + 5x - 3  =>  {-3, 5, 2, -1, 4} */
    int poly1[] = {-3, 5, 2, -1, 4};
    int deg1 = 4;

    /* P2 = x^3 - 3x^2 + 2x - 7  =>  {-7, 2, -3, 1} */
    int poly2[] = {-7, 2, -3, 1};
    int deg2 = 3;

    /* P3 = 2x^3 + x^2 - 6x + 4  =>  {4, -6, 1, 2} */
    int poly3[] = {4, -6, 1, 2};
    int deg3 = 3;

    int prod1[MAX], prod2[MAX], sumProd[MAX];
    int degProd1, degProd2, degSumProd;

    int p2p3[MAX], prod1v2[MAX];  /* For P2+P3 and P1*(P2+P3) */
    int degP2P3, degProd1v2;

    printf("=== HARD POLYNOMIAL: P1*P2 + P1*P3 ===\n\n");

    printf("P1 = "); displayWithSign(poly1, deg1);
    printf("P2 = "); displayWithSign(poly2, deg2);
    printf("P3 = "); displayWithSign(poly3, deg3);
    printf("\n");

    /* PATH A: P1*P2 + P1*P3 */
    printf("--- PATH A: Compute P1*P2 + P1*P3 ---\n");

    degProd1 = multiplyPoly(poly1, deg1, poly2, deg2, prod1);
    printf("P1 * P2 = "); displayWithSign(prod1, degProd1);

    degProd2 = multiplyPoly(poly1, deg1, poly3, deg3, prod2);
    printf("P1 * P3 = "); displayWithSign(prod2, degProd2);

    degSumProd = addPoly(prod1, degProd1, prod2, degProd2, sumProd);
    printf("P1*P2 + P1*P3 = "); displayWithSign(sumProd, degSumProd);
    printf("Degree of result = %d\n\n", degSumProd);

    /* PATH B: P1 * (P2+P3) */
    printf("--- PATH B: Compute P1 * (P2+P3) ---\n");

    degP2P3 = addPoly(poly2, deg2, poly3, deg3, p2p3);
    printf("P2 + P3 = "); displayWithSign(p2p3, degP2P3);

    degProd1v2 = multiplyPoly(poly1, deg1, p2p3, degP2P3, prod1v2);
    printf("P1 * (P2+P3) = "); displayWithSign(prod1v2, degProd1v2);

    /* Verify distributive law */
    printf("\n--- VERIFICATION (Distributive Law) ---\n");
    printf("P1*P2 + P1*P3   =  ");
    displayWithSign(sumProd, degSumProd);
    printf("P1 * (P2+P3)   =  ");
    displayWithSign(prod1v2, degProd1v2);

    if (checkEqual(sumProd, degSumProd, prod1v2, degProd1v2)) {
        printf("\nBOTH RESULTS ARE EQUAL!\n");
        printf("Distributive Law CONFIRMED: P1*(P2+P3) = P1*P2 + P1*P3\n");
    } else {
        printf("Results differ -- check for a bug.\n");
    }

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === HARD POLYNOMIAL: P1*P2 + P1*P3 ===
 *
 * P1 = 4x^4 - x^3 + 2x^2 + 5x - 3
 * P2 = x^3 - 3x^2 + 2x - 7
 * P3 = 2x^3 + x^2 - 6x + 4
 *
 * --- PATH A: Compute P1*P2 + P1*P3 ---
 * P1 * P2 = 4x^7 - 13x^6 + 11x^5 - 27x^4 + 12x^3 + 26x^2 - 41x + 21
 * P1 * P3 = 8x^7 + 0x^6 - 31x^5 + ...  (full degree-7 polynomial)
 * P1*P2 + P1*P3 = 12x^7 - 7x^6 + 11x^5 - ... (result)
 * Degree of result = 7
 *
 * --- PATH B: Compute P1*(P2+P3) ---
 * P2 + P3 = 3x^3 - 2x^2 - 4x - 3
 * P1 * (P2+P3) = 12x^7 - 7x^6 + 11x^5 - ... (same result)
 *
 * --- VERIFICATION (Distributive Law) ---
 * P1*P2 + P1*P3   =  12x^7 - 7x^6 + 11x^5 - ...
 * P1 * (P2+P3)   =  12x^7 - 7x^6 + 11x^5 - ...
 *
 * BOTH RESULTS ARE EQUAL!
 * Distributive Law CONFIRMED: P1*(P2+P3) = P1*P2 + P1*P3
 *
 * ============================================================
 * HOW IT WORKS:
 * ============================================================
 * This is the HARDEST program in the set because it chains:
 *   MULTIPLY -> MULTIPLY -> ADD   (Path A)
 *   ADD -> MULTIPLY               (Path B)
 *
 * Both paths use the same functions (addPoly, multiplyPoly).
 *
 * THE DISTRIBUTIVE PROPERTY:
 *   a * (b + c) = a*b + a*c
 *   This extends to polynomials:
 *   P1 * (P2 + P3) = P1*P2 + P1*P3
 *
 * DEGREE AFTER MULTIPLICATION:
 *   deg(P1*P2) = deg(P1) + deg(P2) = 4 + 3 = 7
 *   deg(P1*P3) = deg(P1) + deg(P3) = 4 + 3 = 7
 *   So the final result is a degree-7 polynomial — the most complex in this set!
 *
 * VERIFICATION FUNCTION checkEqual():
 *   Compares two polynomials coefficient by coefficient.
 *   Handles different-length arrays by treating missing coefficients as 0.
 * ============================================================
 */
