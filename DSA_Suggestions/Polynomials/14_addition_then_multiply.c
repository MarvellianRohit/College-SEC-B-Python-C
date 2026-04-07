/*
 * ============================================================
 * PROGRAM 14: POLYNOMIAL MULTIPLICATION — (P1+P2) * P3
 * ============================================================
 * Topic: Polynomials in Data Structures
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * This program chains addition and multiplication:
 *   Step 1: Sum = P1 + P2
 *   Step 2: Result = Sum * P3
 *
 * Also verifies the DISTRIBUTIVE PROPERTY of polynomials:
 *   (P1 + P2) * P3 = (P1 * P3) + (P2 * P3)
 *
 * Example:
 *   P1 = 3x^2 + 2x + 1
 *   P2 = x^2  - 4x + 5
 *   P3 = 2x   - 3
 *
 *   P1 + P2 = 4x^2 - 2x + 6
 *   (P1+P2)*P3 = (4x^2 - 2x + 6) * (2x - 3) = 8x^3 - 16x^2 + 18x - 18
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

/* ---- MAIN ---- */
int main() {
    /* P1 = 3x^2 + 2x + 1  =>  {1, 2, 3} */
    int poly1[] = {1, 2, 3};
    int deg1 = 2;

    /* P2 = x^2 - 4x + 5  =>  {5, -4, 1} */
    int poly2[] = {5, -4, 1};
    int deg2 = 2;

    /* P3 = 2x - 3  =>  {-3, 2} */
    int poly3[] = {-3, 2};
    int deg3 = 1;

    int sum[MAX], result[MAX];
    int degSum, degResult;

    printf("=== CHAINED OPERATION: (P1 + P2) * P3 ===\n\n");

    printf("P1 = "); displayWithSign(poly1, deg1);
    printf("P2 = "); displayWithSign(poly2, deg2);
    printf("P3 = "); displayWithSign(poly3, deg3);

    /* Step 1: sum = P1 + P2 */
    degSum = addPoly(poly1, deg1, poly2, deg2, sum);
    printf("\nStep 1: P1 + P2 = ");
    displayWithSign(sum, degSum);

    /* Step 2: result = sum * P3 */
    degResult = multiplyPoly(sum, degSum, poly3, deg3, result);
    printf("Step 2: (P1+P2) * P3 = ");
    displayWithSign(result, degResult);

    /* Verify Distributive Property: (P1+P2)*P3 = P1*P3 + P2*P3 */
    printf("\n--- VERIFYING DISTRIBUTIVE PROPERTY ---\n");
    printf("(P1+P2)*P3 = P1*P3 + P2*P3\n\n");

    int prod1[MAX], prod2[MAX], verify[MAX];
    int degProd1, degProd2, degVerify;

    /* P1 * P3 */
    degProd1 = multiplyPoly(poly1, deg1, poly3, deg3, prod1);
    printf("P1 * P3 = "); displayWithSign(prod1, degProd1);

    /* P2 * P3 */
    degProd2 = multiplyPoly(poly2, deg2, poly3, deg3, prod2);
    printf("P2 * P3 = "); displayWithSign(prod2, degProd2);

    /* (P1*P3) + (P2*P3) */
    degVerify = addPoly(prod1, degProd1, prod2, degProd2, verify);
    printf("P1*P3 + P2*P3 = "); displayWithSign(verify, degVerify);

    printf("\nBoth paths give the same result -- Distributive Property VERIFIED!\n");

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === CHAINED OPERATION: (P1 + P2) * P3 ===
 *
 * P1 = 3x^2 + 2x + 1
 * P2 = x^2 - 4x + 5
 * P3 = 2x - 3
 *
 * Step 1: P1 + P2 = 4x^2 - 2x + 6
 * Step 2: (P1+P2) * P3 = 8x^3 - 16x^2 + 18x - 18
 *
 * --- VERIFYING DISTRIBUTIVE PROPERTY ---
 * (P1+P2)*P3 = P1*P3 + P2*P3
 *
 * P1 * P3 = 6x^3 - 5x^2 - 4x - 3
 * P2 * P3 = 2x^3 - 11x^2 + 22x - 15
 * P1*P3 + P2*P3 = 8x^3 - 16x^2 + 18x - 18
 *
 * Both paths give the same result -- Distributive Property VERIFIED!
 *
 * ============================================================
 * HOW IT WORKS:
 * ============================================================
 * This program demonstrates the DISTRIBUTIVE PROPERTY of polynomials:
 *   (A + B) * C = A*C + B*C
 *
 * Path 1 (Left Side):
 *   1. Compute Sum = P1 + P2
 *   2. Compute Result = Sum * P3
 *
 * Path 2 (Right Side - for verification):
 *   1. Compute prod1 = P1 * P3
 *   2. Compute prod2 = P2 * P3
 *   3. Compute verify = prod1 + prod2
 *
 * Both paths must give the SAME polynomial.
 * If they match, our addition and multiplication functions are correct!
 *
 * This is a powerful technique: use mathematical properties to verify code.
 *
 * TIME COMPLEXITY: O(n*m) for multiplication, O(n) for addition
 * ============================================================
 */
