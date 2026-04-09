/*
 * ============================================================
 * PROGRAM 01: POLYNOMIAL ADDITION
 * ============================================================
 * Topic: Polynomials (Simplified Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * This program implements polynomial addition using an array 
 * representation. In this method, the index of the array 
 * represents the power of 'x', and the value stored at that 
 * index represents the coefficient.
 * For example: 3x^2 + 5x + 1 is stored as poly[2]=3, poly[1]=5, poly[0]=1.
 *
 * ALGORITHM:
 * 1. START
 * 2. Input degree and coefficients of Polynomial 1 (P1).
 * 3. Input degree and coefficients of Polynomial 2 (P2).
 * 4. Determine the maximum degree (maxDeg) between P1 and P2.
 * 5. Loop from i = 0 up to maxDeg:
 *    a. Result[i] = P1[i] + P2[i].
 * 6. Display the resulting polynomial.
 * 7. STOP
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

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * === POLYNOMIAL ADDITION ===
 *
 * First Polynomial:
 * Enter degree: 2
 *   Enter coefficient for x^0: 1
 *   Enter coefficient for x^1: 2
 *   Enter coefficient for x^2: 3
 *
 * Second Polynomial:
 * Enter degree: 1
 *   Enter coefficient for x^0: 4
 *   Enter coefficient for x^1: 5
 *
 * First:  3x^2 + 2x^1 + 1x^0 
 * Second: 5x^1 + 4x^0 
 * Sum:    3x^2 + 7x^1 + 5x^0 
 * ============================================================
 */
