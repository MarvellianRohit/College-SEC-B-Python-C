/*
 * ============================================================
 * PROGRAM 01: POLYNOMIAL ADDITION
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * A polynomial like 3x^2 + 5x + 7 can be stored in an array:
 *   Index = Power of x
 *   Value = Coefficient
 *   poly[2] = 3 means 3x^2
 * ============================================================
 */

#include <stdio.h>

#define MAX 10

/* Function to read polynomial coefficients from the user */
void readPoly(int poly[], int degree) {
    for (int i = 0; i <= degree; i++) {
        printf("  Enter coefficient for x^%d: ", i);
        scanf("%d", &poly[i]);
    }
}

/* Function to display the polynomial in readable format */
void displayPoly(int poly[], int degree) {
    for (int i = degree; i >= 0; i--) {
        /* Only print if coefficient is not zero */
        if (poly[i] != 0) {
            printf("%dx^%d ", poly[i], i);
            
            /* Print a '+' sign if there are more terms coming */
            if (i > 0) {
                printf("+ ");
            }
        }
    }
    printf("\n");
}

/* Function to add two polynomials */
int addPoly(int p1[], int d1, int p2[], int d2, int result[]) {
    int maxDeg;
    
    /* Find the higher degree */
    if (d1 > d2) {
        maxDeg = d1;
    } else {
        maxDeg = d2;
    }

    /* Initialize result array to 0 */
    for (int i = 0; i <= maxDeg; i++) {
        result[i] = 0;
    }

    /* Adding first polynomial */
    for (int i = 0; i <= d1; i++) {
        result[i] = result[i] + p1[i];
    }

    /* Adding second polynomial */
    for (int i = 0; i <= d2; i++) {
        result[i] = result[i] + p2[i];
    }

    return maxDeg;
}

int main() {
    int p1[MAX], p2[MAX], sum[MAX];
    int deg1, deg2, degSum;

    printf("=== POLYNOMIAL ADDITION ===\n\n");

    printf("First Polynomial:\n");
    printf("Enter degree: ");
    scanf("%d", &deg1);
    readPoly(p1, deg1);

    printf("\nSecond Polynomial:\n");
    printf("Enter degree: ");
    scanf("%d", &deg2);
    readPoly(p2, deg2);

    degSum = addPoly(p1, deg1, p2, deg2, sum);

    printf("\nFirst:  "); displayPoly(p1, deg1);
    printf("Second: "); displayPoly(p2, deg2);
    printf("Sum:    "); displayPoly(sum, degSum);

    return 0;
}
