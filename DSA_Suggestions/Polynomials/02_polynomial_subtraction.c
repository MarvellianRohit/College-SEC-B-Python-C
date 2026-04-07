/*
 * ============================================================
 * PROGRAM 2: SUBTRACTION OF TWO POLYNOMIALS
 * ============================================================
 * Topic: Polynomials in Data Structures
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * Subtracting poly2 from poly1 means:
 * result[i] = poly1[i] - poly2[i]   (for each power i)
 *
 * Example:
 *   poly1 = 5x^2 + 3x + 8
 *   poly2 = 2x^2 + 1x + 5
 *   result = (5-2)x^2 + (3-1)x + (8-5) = 3x^2 + 2x + 3
 * ============================================================
 */

#include <stdio.h>

#define MAX 10   /* Maximum number of terms supported */

/* ---- FUNCTION: readPolynomial ----
 * Reads coefficients from user input into the polynomial array.
 */
void readPolynomial(int poly[], int degree) {
    int i;
    for (i = 0; i <= degree; i++) {
        printf("  Coefficient of x^%d: ", i);
        scanf("%d", &poly[i]);   /* Store coefficient at index i */
    }
}

/* ---- FUNCTION: subtractPolynomials ----
 * Subtracts poly2 from poly1.
 * result[i] = poly1[i] - poly2[i]
 * If poly2 has a higher degree, then extra terms are subtracted from 0.
 */
int subtractPolynomials(int poly1[], int poly2[], int result[], int deg1, int deg2) {
    int i;
    int maxDeg = (deg1 > deg2) ? deg1 : deg2;  /* Max degree = higher of the two */

    /* Initialize result to zero */
    for (i = 0; i <= maxDeg; i++) {
        result[i] = 0;
    }

    /* Copy poly1 into result (result = poly1 to start) */
    for (i = 0; i <= deg1; i++) {
        result[i] = poly1[i];
    }

    /* Subtract poly2 from result */
    for (i = 0; i <= deg2; i++) {
        result[i] -= poly2[i];   /* result[i] = result[i] - poly2[i] */
    }

    return maxDeg;
}

/* ---- FUNCTION: displayPolynomial ----
 * Displays polynomial in math notation (e.g., 3x^2 + 2x + 3)
 */
void displayPolynomial(int poly[], int degree) {
    int i;
    int firstTerm = 1;

    for (i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            if (!firstTerm) {
                /* If coefficient is negative, print ' - ', else print ' + ' */
                if (poly[i] > 0)
                    printf(" + ");
                else
                    printf(" - ");
            }

            /* Print absolute value of coefficient */
            int coeff = (poly[i] < 0 && !firstTerm) ? -poly[i] : poly[i];

            if (i == 0)       printf("%d", coeff);
            else if (i == 1)  printf("%dx", coeff);
            else              printf("%dx^%d", coeff, i);

            firstTerm = 0;
        }
    }
    printf("\n");
}

/* ---- MAIN FUNCTION ---- */
int main() {
    int poly1[MAX], poly2[MAX], result[MAX];
    int deg1, deg2, resultDeg;

    printf("=== POLYNOMIAL SUBTRACTION (poly1 - poly2) ===\n\n");

    printf("Enter degree of first polynomial: ");
    scanf("%d", &deg1);
    printf("Coefficients of first polynomial (x^0 to x^%d):\n", deg1);
    readPolynomial(poly1, deg1);

    printf("\nEnter degree of second polynomial: ");
    scanf("%d", &deg2);
    printf("Coefficients of second polynomial (x^0 to x^%d):\n", deg2);
    readPolynomial(poly2, deg2);

    /* Perform subtraction */
    resultDeg = subtractPolynomials(poly1, poly2, result, deg1, deg2);

    /* Display results */
    printf("\nFirst Polynomial:   ");
    displayPolynomial(poly1, deg1);

    printf("Second Polynomial:  ");
    displayPolynomial(poly2, deg2);

    printf("Difference (P1-P2): ");
    displayPolynomial(result, resultDeg);

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === POLYNOMIAL SUBTRACTION (poly1 - poly2) ===
 *
 * Enter degree of first polynomial: 2
 * Coefficients of first polynomial (x^0 to x^2):
 *   Coefficient of x^0: 8
 *   Coefficient of x^1: 3
 *   Coefficient of x^2: 5
 *
 * Enter degree of second polynomial: 2
 * Coefficients of second polynomial (x^0 to x^2):
 *   Coefficient of x^0: 5
 *   Coefficient of x^1: 1
 *   Coefficient of x^2: 2
 *
 * First Polynomial:   5x^2 + 3x + 8
 * Second Polynomial:  2x^2 + 1x + 5
 * Difference (P1-P2): 3x^2 + 2x + 3
 *
 * ============================================================
 * HOW IT WORKS:
 * ============================================================
 * 1. We represent polynomials as arrays (same as addition).
 * 2. To subtract, we simply subtract coefficients at the same index.
 * 3. If poly2 has more terms than poly1, those extra terms get
 *    subtracted from 0 (which makes them negative in the result).
 *
 * KEY DIFFERENCE FROM ADDITION:
 *   Addition:    result[i] = poly1[i] + poly2[i]
 *   Subtraction: result[i] = poly1[i] - poly2[i]
 *
 * TIME COMPLEXITY: O(max degree)
 * SPACE COMPLEXITY: O(max degree)
 * ============================================================
 */
