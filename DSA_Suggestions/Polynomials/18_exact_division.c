/*
 * ============================================================
 * PROGRAM 18: DIVISION — EXACT CASE (NO REMAINDER)
 * ============================================================
 * Topic: Polynomials in Data Structures
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * In this program, the dividend is perfectly divisible by the divisor.
 * That means: remainder = 0 (exact division).
 *
 * This happens when the divisor is a FACTOR of the dividend.
 * Example:
 *   dividend = x^4 - 5x^3 + 5x^2 + 5x - 6
 *   divisor  = x^2 - 4x + 3
 *
 *   These are related by: (x-1)(x-2)(x-3)(x+1) and (x-1)(x-3)
 *   So division gives: x^2 - x - 2 with remainder 0.
 *
 * Easier verified example we'll use:
 *   dividend = x^3 - 6x^2 + 11x - 6   (= (x-1)(x-2)(x-3))
 *   divisor  = x - 2
 *   quotient should be x^2 - 4x + 3   (= (x-1)(x-3))
 *   remainder = 0 (exact)
 * ============================================================
 */

#include <stdio.h>
#include <math.h>

#define MAX 20

/* ---- FUNCTION: displayFloat ----
 * Displays polynomial with float coefficients.
 */
void displayFloat(float poly[], int degree) {
    int i, first = 1;
    for (i = degree; i >= 0; i--) {
        if (poly[i] > -0.0001 && poly[i] < 0.0001) continue;  /* Skip ~0 terms */
        if (first) {
            if (i == 0)      printf("%.0f", poly[i]);
            else if (i == 1) printf("%.0fx", poly[i]);
            else             printf("%.0fx^%d", poly[i], i);
            first = 0;
        } else {
            if (poly[i] > 0) {
                printf(" + ");
                if (i == 0)      printf("%.0f", poly[i]);
                else if (i == 1) printf("%.0fx", poly[i]);
                else             printf("%.0fx^%d", poly[i], i);
            } else {
                printf(" - ");
                float a = -poly[i];
                if (i == 0)      printf("%.0f", a);
                else if (i == 1) printf("%.0fx", a);
                else             printf("%.0fx^%d", a, i);
            }
        }
    }
    if (first) printf("0");
    printf("\n");
}

/* ---- FUNCTION: polynomialDivision ----
 * Performs polynomial long division.
 */
void polynomialDivision(float dividend[], int degD,
                         float divisor[],  int degR,
                         float quotient[], int *degQ,
                         float remainder[], int *degRem) {
    int i, j;
    float temp[MAX];

    for (i = 0; i <= degD; i++) temp[i] = dividend[i];
    for (i = degD + 1; i < MAX; i++) temp[i] = 0.0f;

    *degQ = degD - degR;

    for (i = 0; i <= *degQ; i++) quotient[i] = 0.0f;

    for (i = degD; i >= degR; i--) {
        float qCoeff = temp[i] / divisor[degR];
        quotient[i - degR] = qCoeff;
        for (j = 0; j <= degR; j++) {
            temp[i - degR + j] -= qCoeff * divisor[j];
        }
    }

    *degRem = degR - 1;
    for (i = 0; i <= *degRem; i++) {
        remainder[i] = temp[i];
    }
}

/* ---- MAIN ---- */
int main() {
    /* Dividend = x^3 - 6x^2 + 11x - 6  =>  {-6, 11, -6, 1} */
    float dividend[] = {-6.0, 11.0, -6.0, 1.0};
    int degD = 3;

    /* Divisor = x - 2  =>  {-2, 1} */
    float divisor[] = {-2.0, 1.0};
    int degR = 1;

    float quotient[MAX], remainder[MAX];
    int degQ, degRem;

    printf("=== EXACT POLYNOMIAL DIVISION (Remainder = 0) ===\n\n");
    printf("We use: x^3 - 6x^2 + 11x - 6 = (x-1)(x-2)(x-3)\n");
    printf("Dividing by (x-2) should give (x-1)(x-3) = x^2 - 4x + 3\n\n");

    printf("Dividend : ");
    displayFloat(dividend, degD);

    printf("Divisor  : ");
    displayFloat(divisor, degR);

    /* Perform division */
    polynomialDivision(dividend, degD, divisor, degR,
                       quotient, &degQ, remainder, &degRem);

    printf("\nQuotient : ");
    displayFloat(quotient, degQ);

    printf("Remainder: ");
    displayFloat(remainder, degRem);

    /* Check if remainder is zero */
    float remAbs = remainder[0] < 0 ? -remainder[0] : remainder[0];
    if (remAbs < 0.001) {
        printf("\nREMAINDER IS ZERO -> Exact division!\n");
        printf("This means (x-2) is a FACTOR of the dividend.\n");
        printf("Result: x^3 - 6x^2 + 11x - 6 = (x - 2) * (");
        displayFloat(quotient, degQ);
        printf(")\n");
    } else {
        printf("\nRemainder is non-zero -> Not exact division.\n");
    }

    /* Also divide by (x-1) and (x-3) to show all three factors */
    printf("\n--- Also dividing by (x-1) ---\n");
    float d2[] = {-1.0, 1.0};
    float q2[MAX], r2[MAX];
    int dq2, dr2;
    polynomialDivision(dividend, degD, d2, 1, q2, &dq2, r2, &dr2);
    printf("Quotient : "); displayFloat(q2, dq2);
    printf("Remainder: "); displayFloat(r2, dr2);

    printf("\n--- Also dividing by (x-3) ---\n");
    float d3[] = {-3.0, 1.0};
    float q3[MAX], r3[MAX];
    int dq3, dr3;
    polynomialDivision(dividend, degD, d3, 1, q3, &dq3, r3, &dr3);
    printf("Quotient : "); displayFloat(q3, dq3);
    printf("Remainder: "); displayFloat(r3, dr3);

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === EXACT POLYNOMIAL DIVISION (Remainder = 0) ===
 *
 * We use: x^3 - 6x^2 + 11x - 6 = (x-1)(x-2)(x-3)
 * Dividing by (x-2) should give (x-1)(x-3) = x^2 - 4x + 3
 *
 * Dividend : x^3 - 6x^2 + 11x - 6
 * Divisor  : x - 2
 *
 * Quotient : x^2 - 4x + 3
 * Remainder: 0
 *
 * REMAINDER IS ZERO -> Exact division!
 * This means (x-2) is a FACTOR of the dividend.
 * Result: x^3 - 6x^2 + 11x - 6 = (x - 2) * (x^2 - 4x + 3)
 *
 * --- Also dividing by (x-1) ---
 * Quotient : x^2 - 5x + 6
 * Remainder: 0
 *
 * --- Also dividing by (x-3) ---
 * Quotient : x^2 - 3x + 2
 * Remainder: 0
 *
 * ============================================================
 * HOW IT WORKS:
 * ============================================================
 * We use the same long division algorithm as Program 05.
 *
 * In this program we chose a SPECIAL polynomial: x^3 - 6x^2 + 11x - 6
 * This is equal to (x-1)(x-2)(x-3), so x=1, 2, 3 are its roots.
 *
 * When we divide by (x-k) where k is a root, the remainder is ALWAYS 0.
 * This is called the FACTOR THEOREM:
 *   "If P(k) = 0, then (x-k) divides P(x) exactly."
 *
 * We demonstrate this for all three roots:
 *   x^3-6x^2+11x-6 ÷ (x-1) = x^2-5x+6  (no remainder)
 *   x^3-6x^2+11x-6 ÷ (x-2) = x^2-4x+3  (no remainder)
 *   x^3-6x^2+11x-6 ÷ (x-3) = x^2-3x+2  (no remainder)
 *
 * KEY INSIGHT:
 *   If P(k) ≠ 0, then (x-k) is NOT a factor and there will be a remainder.
 *   This links polynomial division to root-finding!
 * ============================================================
 */
