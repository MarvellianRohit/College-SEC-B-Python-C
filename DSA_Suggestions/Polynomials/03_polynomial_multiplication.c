/*
 * ============================================================
 * PROGRAM 3: MULTIPLICATION OF TWO POLYNOMIALS
 * ============================================================
 * Topic: Polynomials in Data Structures
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * When multiplying two polynomials, every term of poly1 is
 * multiplied with every term of poly2.
 *
 * Example:
 *   poly1 = 3x + 2  (i.e., poly1[0]=2, poly1[1]=3)
 *   poly2 = 2x + 5  (i.e., poly2[0]=5, poly2[1]=2)
 *
 *   (3x + 2) * (2x + 5)
 *   = 3x*2x + 3x*5 + 2*2x + 2*5
 *   = 6x^2  + 15x  + 4x  + 10
 *   = 6x^2  + 19x  + 10
 *
 * In terms of indices:
 *   result[i + j] += poly1[i] * poly2[j]
 * ============================================================
 */

#include <stdio.h>

#define MAX 20   /* Result can have degree up to (deg1 + deg2), so size must be bigger */

/* ---- FUNCTION: readPolynomial ---- */
void readPolynomial(int poly[], int degree) {
    int i;
    for (i = 0; i <= degree; i++) {
        printf("  Coefficient of x^%d: ", i);
        scanf("%d", &poly[i]);
    }
}

/* ---- FUNCTION: multiplyPolynomials ----
 * KEY LOGIC: For every term i in poly1 and every term j in poly2,
 * multiply them and add the result to result[i+j].
 * Why i+j? Because x^i * x^j = x^(i+j) (power rule).
 */
int multiplyPolynomials(int poly1[], int poly2[], int result[], int deg1, int deg2) {
    int i, j;
    int resultDeg = deg1 + deg2;   /* Degree of result is sum of both degrees */

    /* Initialize result to 0 */
    for (i = 0; i <= resultDeg; i++) {
        result[i] = 0;
    }

    /* Multiply each term of poly1 with each term of poly2 */
    for (i = 0; i <= deg1; i++) {          /* Loop through poly1 */
        for (j = 0; j <= deg2; j++) {      /* Loop through poly2 */
            result[i + j] += poly1[i] * poly2[j];
            /* result at power (i+j) += coefficient product */
        }
    }

    return resultDeg;
}

/* ---- FUNCTION: displayPolynomial ---- */
void displayPolynomial(int poly[], int degree) {
    int i;
    int firstTerm = 1;

    for (i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            if (!firstTerm) printf(" + ");

            if (i == 0)      printf("%d", poly[i]);
            else if (i == 1) printf("%dx", poly[i]);
            else             printf("%dx^%d", poly[i], i);

            firstTerm = 0;
        }
    }
    printf("\n");
}

/* ---- MAIN FUNCTION ---- */
int main() {
    int poly1[MAX], poly2[MAX], result[MAX];
    int deg1, deg2, resultDeg;

    printf("=== POLYNOMIAL MULTIPLICATION ===\n\n");

    printf("Enter degree of first polynomial: ");
    scanf("%d", &deg1);
    printf("Coefficients (x^0 to x^%d):\n", deg1);
    readPolynomial(poly1, deg1);

    printf("\nEnter degree of second polynomial: ");
    scanf("%d", &deg2);
    printf("Coefficients (x^0 to x^%d):\n", deg2);
    readPolynomial(poly2, deg2);

    resultDeg = multiplyPolynomials(poly1, poly2, result, deg1, deg2);

    printf("\nFirst Polynomial:  ");
    displayPolynomial(poly1, deg1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2, deg2);

    printf("Product:           ");
    displayPolynomial(result, resultDeg);

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === POLYNOMIAL MULTIPLICATION ===
 *
 * Enter degree of first polynomial: 1
 * Coefficients (x^0 to x^1):
 *   Coefficient of x^0: 2
 *   Coefficient of x^1: 3
 *
 * Enter degree of second polynomial: 1
 * Coefficients (x^0 to x^1):
 *   Coefficient of x^0: 5
 *   Coefficient of x^1: 2
 *
 * First Polynomial:  3x + 2
 * Second Polynomial: 2x + 5
 * Product:           6x^2 + 19x + 10
 *
 * ============================================================
 * HOW IT WORKS:
 * ============================================================
 * NESTED LOOPS:
 *   Outer loop: goes through each term of poly1 (index i)
 *   Inner loop: goes through each term of poly2 (index j)
 *
 * For each pair (i, j):
 *   - Multiply the coefficients: poly1[i] * poly2[j]
 *   - The new power = i + j  (because x^i * x^j = x^(i+j))
 *   - Add this value to result[i+j]
 *
 * WHY DOES THE RESULT DEGREE = deg1 + deg2?
 *   The highest term in poly1 is x^deg1
 *   The highest term in poly2 is x^deg2
 *   Multiplying them gives x^(deg1+deg2)
 *
 * TIME COMPLEXITY: O(deg1 * deg2) - because of nested loops
 * SPACE COMPLEXITY: O(deg1 + deg2) - result array size
 * ============================================================
 */
