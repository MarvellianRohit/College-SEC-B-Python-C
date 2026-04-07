/*
 * ============================================================
 * PROGRAM 1: ADDITION OF TWO POLYNOMIALS
 * ============================================================
 * Topic: Polynomials in Data Structures
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS A POLYNOMIAL?
 * A polynomial is a mathematical expression like:
 *   3x^2 + 5x + 7
 * It has terms, each term has a COEFFICIENT and a POWER (exponent).
 * Example: 3x^2 -> coefficient = 3, power = 2
 *
 * HOW DO WE STORE A POLYNOMIAL IN C?
 * We use an ARRAY where:
 *   index = power of x
 *   value = coefficient
 * So poly[2] = 3 means 3x^2
 * ============================================================
 */

#include <stdio.h>   /* For printf and scanf */

#define MAX 10       /* Maximum degree of polynomial (we support up to degree 9) */

/* ---- FUNCTION: readPolynomial ----
 * This function reads terms of a polynomial from the user.
 * Parameters:
 *   poly[] - the array to store coefficients
 *   degree - the highest power of x
 */
void readPolynomial(int poly[], int degree) {
    int i;
    /* Loop from 0 to degree (inclusive) to read each coefficient */
    for (i = 0; i <= degree; i++) {
        printf("  Enter coefficient of x^%d: ", i);  /* Ask user for each term */
        scanf("%d", &poly[i]);                         /* Store it in array at index i */
    }
}

/* ---- FUNCTION: addPolynomials ----
 * Adds two polynomials term by term and stores result in result[].
 * Terms with the same power are added together.
 * Parameters:
 *   poly1[], poly2[] - input polynomials
 *   result[]         - output polynomial (sum)
 *   deg1, deg2       - degrees of poly1 and poly2
 */
int addPolynomials(int poly1[], int poly2[], int result[], int deg1, int deg2) {
    int i;
    int maxDeg = (deg1 > deg2) ? deg1 : deg2;  /* Find the higher degree */

    /* Initialize result array to zero for all positions */
    for (i = 0; i <= maxDeg; i++) {
        result[i] = 0;
    }

    /* Add terms of poly1 into result */
    for (i = 0; i <= deg1; i++) {
        result[i] += poly1[i];   /* result[i] = result[i] + poly1[i] */
    }

    /* Add terms of poly2 into result */
    for (i = 0; i <= deg2; i++) {
        result[i] += poly2[i];   /* result[i] = result[i] + poly2[i] */
    }

    return maxDeg;  /* Return the degree of the result polynomial */
}

/* ---- FUNCTION: displayPolynomial ----
 * Displays the polynomial in a readable mathematical format.
 * e.g., 3x^2 + 5x^1 + 7x^0
 */
void displayPolynomial(int poly[], int degree) {
    int i;
    int firstTerm = 1;  /* Flag to avoid printing '+' before the first term */

    for (i = degree; i >= 0; i--) {   /* Start from highest power to lowest */
        if (poly[i] != 0) {           /* Skip terms with 0 coefficient */
            if (!firstTerm) {
                printf(" + ");         /* Print '+' between terms */
            }
            if (i == 0) {
                printf("%d", poly[i]);          /* Constant term: just print number */
            } else if (i == 1) {
                printf("%dx", poly[i]);         /* Linear term: e.g., 5x */
            } else {
                printf("%dx^%d", poly[i], i);   /* Higher terms: e.g., 3x^2 */
            }
            firstTerm = 0;
        }
    }
    printf("\n");
}

/* ---- MAIN FUNCTION ---- */
int main() {
    int poly1[MAX], poly2[MAX], result[MAX]; /* Arrays for two polynomials and result */
    int deg1, deg2, resultDeg;               /* Degrees of each polynomial */

    printf("=== POLYNOMIAL ADDITION ===\n\n");

    /* Read first polynomial */
    printf("Enter degree of first polynomial: ");
    scanf("%d", &deg1);
    printf("Enter coefficients for first polynomial (starting from x^0):\n");
    readPolynomial(poly1, deg1);

    /* Read second polynomial */
    printf("\nEnter degree of second polynomial: ");
    scanf("%d", &deg2);
    printf("Enter coefficients for second polynomial (starting from x^0):\n");
    readPolynomial(poly2, deg2);

    /* Perform addition */
    resultDeg = addPolynomials(poly1, poly2, result, deg1, deg2);

    /* Display all three polynomials */
    printf("\nFirst Polynomial:  ");
    displayPolynomial(poly1, deg1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2, deg2);

    printf("Sum:               ");
    displayPolynomial(result, resultDeg);

    return 0;  /* Program ends successfully */
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === POLYNOMIAL ADDITION ===
 *
 * Enter degree of first polynomial: 2
 * Enter coefficients for first polynomial (starting from x^0):
 *   Enter coefficient of x^0: 7
 *   Enter coefficient of x^1: 5
 *   Enter coefficient of x^2: 3
 *
 * Enter degree of second polynomial: 2
 * Enter coefficients for second polynomial (starting from x^0):
 *   Enter coefficient of x^0: 2
 *   Enter coefficient of x^1: 4
 *   Enter coefficient of x^2: 1
 *
 * First Polynomial:  3x^2 + 5x + 7
 * Second Polynomial: 1x^2 + 4x + 2
 * Sum:               4x^2 + 9x + 9
 *
 * ============================================================
 * HOW IT WORKS:
 * ============================================================
 * 1. We represent a polynomial as an array of integers.
 *    Example: 3x^2 + 5x + 7 => poly[] = {7, 5, 3}
 *             (index 0 = constant, index 1 = x, index 2 = x^2)
 *
 * 2. To ADD two polynomials, we simply add their coefficients
 *    at the SAME INDEX (same power):
 *    result[i] = poly1[i] + poly2[i]
 *
 * 3. We display starting from the highest power going down,
 *    skipping any terms where coefficient = 0.
 *
 * TIME COMPLEXITY: O(max(deg1, deg2)) - we loop once through the larger polynomial
 * SPACE COMPLEXITY: O(max(deg1, deg2)) - we store result in an array
 * ============================================================
 */
