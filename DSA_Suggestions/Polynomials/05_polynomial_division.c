/*
 * ============================================================
 * PROGRAM 5: POLYNOMIAL LONG DIVISION
 * ============================================================
 * Topic: Polynomials in Data Structures
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * Polynomial division is similar to regular long division.
 * We divide dividend by divisor to get:
 *    dividend = (divisor * quotient) + remainder
 *
 * Example:
 *   dividend = 6x^3 + 5x^2 + 4x + 1
 *   divisor  = 2x + 1
 *
 * Step 1: Divide leading term: 6x^3 / 2x = 3x^2  (first term of quotient)
 * Step 2: Multiply divisor by 3x^2: 6x^3 + 3x^2
 * Step 3: Subtract from dividend: (5x^2 - 3x^2) + 4x + 1 = 2x^2 + 4x + 1
 * Step 4: Repeat...
 *
 * We implement this using arrays.
 * ============================================================
 */

#include <stdio.h>

#define MAX 20

/* ---- FUNCTION: displayPolynomial ----
 * Displays polynomial neatly.
 */
void displayPolynomial(float poly[], int degree) {
    int i;
    int firstTerm = 1;

    for (i = degree; i >= 0; i--) {
        if (poly[i] != 0.0f) {
            if (!firstTerm) {
                if (poly[i] > 0) printf(" + ");
                else             printf(" - ");
            }
            float c = (poly[i] < 0 && !firstTerm) ? -poly[i] : poly[i];
            if (i == 0)      printf("%.2f", c);
            else if (i == 1) printf("%.2fx", c);
            else             printf("%.2fx^%d", c, i);
            firstTerm = 0;
        }
    }
    if (firstTerm) printf("0");   /* All zero polynomial */
    printf("\n");
}

/* ---- FUNCTION: polynomialDivision ----
 * Performs polynomial long division.
 * dividend[] / divisor[] = quotient[] + remainder[]
 *
 * Algorithm:
 * 1. Start from the highest power term of dividend.
 * 2. Divide it by the leading term of divisor -> get term of quotient.
 * 3. Multiply divisor by that quotient term.
 * 4. Subtract from current dividend.
 * 5. Repeat until degree of remainder < degree of divisor.
 */
void polynomialDivision(float dividend[], int degD,
                         float divisor[],  int degR,
                         float quotient[], int *degQ,
                         float remainder[], int *degRem) {
    int i, j;
    float temp[MAX];   /* Temporary array for intermediate dividend */

    /* Copy dividend into temp (we'll modify temp during division) */
    for (i = 0; i <= degD; i++) temp[i] = dividend[i];
    for (i = degD + 1; i < MAX; i++) temp[i] = 0;

    *degQ = degD - degR;   /* Degree of quotient = degree of dividend - degree of divisor */

    /* Initialize quotient to 0 */
    for (i = 0; i <= *degQ; i++) quotient[i] = 0;

    /* Perform long division step by step */
    for (i = degD; i >= degR; i--) {
        /* Current quotient term: divide leading term of temp by leading term of divisor */
        float qCoeff = temp[i] / divisor[degR];   /* This is the next quotient coefficient */
        quotient[i - degR] = qCoeff;              /* Store in quotient at correct power */

        /* Subtract (divisor * qCoeff * x^(i-degR)) from temp */
        for (j = 0; j <= degR; j++) {
            temp[i - degR + j] -= qCoeff * divisor[j];
            /* Eliminate the current leading term from temp */
        }
    }

    /* Whatever is left in temp is the remainder */
    *degRem = degR - 1;   /* Remainder degree is at most (divisor degree - 1) */
    for (i = 0; i <= *degRem; i++) {
        remainder[i] = temp[i];
    }
}

/* ---- MAIN FUNCTION ---- */
int main() {
    /* Let's use hardcoded example for clarity:
     * dividend = 6x^3 + 5x^2 + 4x + 1  => {1, 4, 5, 6}
     * divisor  = 2x + 1                  => {1, 2}
     */
    float dividend[] = {1, 4, 5, 6};   /* Coefficients: index = power */
    float divisor[]  = {1, 2};
    float quotient[MAX], remainder[MAX];
    int degD = 3, degR = 1;
    int degQ, degRem;

    printf("=== POLYNOMIAL LONG DIVISION ===\n\n");

    printf("Dividend : ");
    displayPolynomial(dividend, degD);

    printf("Divisor  : ");
    displayPolynomial(divisor, degR);

    /* Divide */
    polynomialDivision(dividend, degD, divisor, degR, quotient, &degQ, remainder, &degRem);

    printf("\nQuotient  : ");
    displayPolynomial(quotient, degQ);

    printf("Remainder : ");
    displayPolynomial(remainder, degRem);

    /* Verify: dividend = divisor * quotient + remainder */
    printf("\nVerification: dividend = (divisor * quotient) + remainder\n");
    printf("           6x^3 + 5x^2 + 4x + 1 = (2x + 1) * quotient + remainder\n");

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === POLYNOMIAL LONG DIVISION ===
 *
 * Dividend : 6.00x^3 + 5.00x^2 + 4.00x + 1.00
 * Divisor  : 2.00x + 1.00
 *
 * Quotient  : 3.00x^2 + 1.00x + 1.50
 * Remainder : -0.50
 *
 * Verification: dividend = (divisor * quotient) + remainder
 *            6x^3 + 5x^2 + 4x + 1 = (2x + 1) * quotient + remainder
 *
 * ============================================================
 * HOW IT WORKS (Long Division Steps):
 * ============================================================
 * Dividing: (6x^3 + 5x^2 + 4x + 1) ÷ (2x + 1)
 *
 * Step 1: 6x^3 ÷ 2x = 3x^2  -> first quotient term
 *         Subtract: (6x^3+5x^2) - (3x^2)(2x+1) = (6x^3+5x^2) - (6x^3+3x^2) = 2x^2+4x+1
 *
 * Step 2: 2x^2 ÷ 2x = 1x  -> second quotient term
 *         Subtract: (2x^2+4x) - (1x)(2x+1) = (2x^2+4x) - (2x^2+x) = 3x+1
 *
 * Step 3: 3x ÷ 2x = 1.5  -> third quotient term
 *         Subtract: (3x+1) - (1.5)(2x+1) = (3x+1) - (3x+1.5) = -0.5
 *
 * Quotient = 3x^2 + x + 1.5,  Remainder = -0.5
 *
 * TIME COMPLEXITY: O(n * m) where n = degree of dividend, m = degree of divisor
 * ============================================================
 */
