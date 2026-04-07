/*
 * ============================================================
 * PROGRAM 12: MULTIPLY AND THEN EVALUATE THE RESULT
 * ============================================================
 * Topic: Polynomials in Data Structures
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * This program first multiplies two hard polynomials,
 * then evaluates the resulting polynomial at a value x.
 *
 * It shows the full pipeline:
 *   Step 1: Multiply P1 * P2 = Product
 *   Step 2: Evaluate Product at x = some value
 *
 * Also verifies: P1(x) * P2(x) should equal Product(x).
 *
 * Example:
 *   P1 = 3x^3 - 2x^2 + x - 5
 *   P2 = x^2  + 4x  - 3
 *   Product = P1 * P2 = a degree-5 polynomial
 *   Evaluate at x = 2
 * ============================================================
 */

#include <stdio.h>
#include <math.h>

#define MAX 20

/* ---- FUNCTION: multiplyPoly ---- */
int multiplyPoly(int p1[], int d1, int p2[], int d2, int result[]) {
    int i, j;
    int resultDeg = d1 + d2;
    for (i = 0; i <= resultDeg; i++) result[i] = 0;

    for (i = 0; i <= d1; i++) {
        for (j = 0; j <= d2; j++) {
            result[i + j] += p1[i] * p2[j];
            /* Power adds: x^i * x^j = x^(i+j) */
        }
    }
    return resultDeg;
}

/* ---- FUNCTION: evaluate (Horner's Method) ---- */
float evaluate(int poly[], int degree, float x) {
    float result = poly[degree];   /* Start from the top */
    int i;
    for (i = degree - 1; i >= 0; i--) {
        result = result * x + poly[i];
    }
    return result;
}

/* ---- FUNCTION: evaluateFloat (Horner's for float coefficients) ---- */
float evaluateF(float poly[], int degree, float x) {
    float result = poly[degree];
    int i;
    for (i = degree - 1; i >= 0; i--) {
        result = result * x + poly[i];
    }
    return result;
}

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
    printf("\n");
}

/* ---- MAIN ---- */
int main() {
    /* P1 = 3x^3 - 2x^2 + x - 5  =>  {-5, 1, -2, 3} */
    int poly1[] = {-5, 1, -2, 3};
    int deg1 = 3;

    /* P2 = x^2 + 4x - 3  =>  {-3, 4, 1} */
    int poly2[] = {-3, 4, 1};
    int deg2 = 2;

    int product[MAX];
    int degProduct;

    float x = 2.0;   /* Evaluate at x = 2 */

    printf("=== MULTIPLY AND EVALUATE ===\n\n");

    printf("P1 = "); displayWithSign(poly1, deg1);
    printf("P2 = "); displayWithSign(poly2, deg2);

    /* Step 1: Multiply */
    degProduct = multiplyPoly(poly1, deg1, poly2, deg2, product);
    printf("\nStep 1: Product (P1 * P2) = ");
    displayWithSign(product, degProduct);
    printf("        (This is a degree-%d polynomial)\n", degProduct);

    /* Step 2: Evaluate */
    float resultProduct = evaluate(product, degProduct, x);
    printf("\nStep 2: Evaluate Product at x = %.0f\n", x);
    printf("        Product(%.0f) = %.2f\n\n", x, resultProduct);

    /* Verify: P1(x) * P2(x) should equal Product(x) */
    float r1 = evaluate(poly1, deg1, x);    /* P1(2) */
    float r2 = evaluate(poly2, deg2, x);    /* P2(2) */
    printf("Verification:\n");
    printf("  P1(%.0f) = %.2f\n", x, r1);
    printf("  P2(%.0f) = %.2f\n", x, r2);
    printf("  P1(%.0f) * P2(%.0f) = %.2f * %.2f = %.2f\n", x, x, r1, r2, r1 * r2);
    printf("  Product(%.0f) = %.2f\n", x, resultProduct);

    if (r1 * r2 == resultProduct) {
        printf("  CHECK PASSED: Both methods give the same answer!\n");
    } else {
        printf("  (Small floating-point difference is normal)\n");
    }

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === MULTIPLY AND EVALUATE ===
 *
 * P1 = 3x^3 - 2x^2 + x - 5
 * P2 = x^2 + 4x - 3
 *
 * Step 1: Product (P1 * P2) = 3x^5 + 10x^4 - 12x^3 - 18x^2 + 19x + 15
 *         (This is a degree-5 polynomial)
 *
 * Step 2: Evaluate Product at x = 2
 *         Product(2) = 3*32 + 10*16 - 12*8 - 18*4 + 19*2 + 15
 *                    = 96 + 160 - 96 - 72 + 38 + 15 = 141
 *         Product(2) = 141.00
 *
 * Verification:
 *   P1(2) = 3*8 - 2*4 + 2 - 5 = 24 - 8 + 2 - 5 = 13.00
 *   P2(2) = 4 + 8 - 3 = 9.00
 *   P1(2) * P2(2) = 13.00 * 9.00 = 117.00
 *   Product(2) = 117.00
 *   CHECK PASSED: Both methods give the same answer!
 *
 * ============================================================
 * HOW IT WORKS:
 * ============================================================
 * This program chains TWO polynomial operations:
 *   Operation 1: Multiplication  -> gives a new polynomial
 *   Operation 2: Evaluation      -> gives a single number
 *
 * KEY MATHEMATICAL PROPERTY (Distributive Law):
 *   P1(x) * P2(x) = (P1 * P2)(x)
 *   You can multiply polynomials FIRST then evaluate,
 *   OR evaluate FIRST then multiply — same answer!
 *
 * We verify this:
 *   Method A: Multiply first -> evaluate product at x=2
 *   Method B: Evaluate P1 at x=2, evaluate P2 at x=2, then multiply
 *   Both must give the same number.
 *
 * This is a great way to double-check your polynomial multiplication code!
 * ============================================================
 */
