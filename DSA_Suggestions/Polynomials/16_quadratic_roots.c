/*
 * ============================================================
 * PROGRAM 16: FIND QUADRATIC ROOTS (ax^2 + bx + c = 0)
 * ============================================================
 * Topic: Polynomials in Data Structures
 * Language: C
 * Level: 1st Year BCA
 *
 * CONCEPT:
 * A quadratic equation is: ax^2 + bx + c = 0
 * We solve it using the QUADRATIC FORMULA:
 *   x = (-b ± sqrt(b^2 - 4ac)) / 2a
 *
 * The term (b^2 - 4ac) is called the DISCRIMINANT (D).
 * Three possible cases:
 *   D > 0: Two distinct REAL roots
 *   D = 0: Two EQUAL real roots (repeated root)
 *   D < 0: Two COMPLEX (imaginary) roots (no real solution)
 *
 * Example:
 *   3x^2 - 10x + 8 = 0
 *   D = (-10)^2 - 4*3*8 = 100 - 96 = 4 > 0
 *   x = (10 ± 2) / 6
 *   x1 = 12/6 = 2,  x2 = 8/6 = 1.333
 * ============================================================
 */

#include <stdio.h>
#include <math.h>   /* For sqrt() */

/* ---- FUNCTION: findRoots ----
 * Finds and prints the roots of ax^2 + bx + c = 0.
 */
void findRoots(float a, float b, float c) {
    float discriminant;    /* D = b^2 - 4ac */
    float x1, x2;          /* The two roots */
    float realPart, imagPart;

    /* If a = 0, it's not a quadratic; it's linear: bx + c = 0 */
    if (a == 0) {
        if (b == 0) {
            printf("  Degenerate equation (both a and b are 0)\n");
        } else {
            printf("  Linear equation: x = %.4f\n", -c / b);
        }
        return;
    }

    /* Calculate discriminant */
    discriminant = b * b - 4 * a * c;

    printf("  Discriminant D = b^2 - 4ac = %.2f^2 - 4*%.2f*%.2f = %.4f\n",
           b, a, c, discriminant);

    if (discriminant > 0) {
        /* Two distinct real roots */
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("  D > 0 --> Two distinct real roots:\n");
        printf("    x1 = (%.2f + sqrt(%.4f)) / (2*%.2f) = %.6f\n",
               -b, discriminant, a, x1);
        printf("    x2 = (%.2f - sqrt(%.4f)) / (2*%.2f) = %.6f\n",
               -b, discriminant, a, x2);
    } else if (discriminant == 0) {
        /* Repeated root */
        x1 = -b / (2 * a);
        printf("  D = 0 --> Two equal (repeated) real roots:\n");
        printf("    x1 = x2 = %.6f\n", x1);
    } else {
        /* Complex roots */
        realPart = -b / (2 * a);
        imagPart = sqrt(-discriminant) / (2 * a);   /* sqrt of |D| */
        printf("  D < 0 --> Two complex (imaginary) roots:\n");
        printf("    x1 = %.4f + %.4fi\n", realPart, imagPart);
        printf("    x2 = %.4f - %.4fi\n", realPart, imagPart);
    }
}

/* ---- MAIN ---- */
int main() {
    printf("=== QUADRATIC POLYNOMIAL ROOT FINDER ===\n");
    printf("    Equation form: ax^2 + bx + c = 0\n\n");

    /* Test Case 1: Two real distinct roots */
    printf("Test 1: 3x^2 - 10x + 8 = 0\n");
    findRoots(3, -10, 8);
    printf("\n");

    /* Test Case 2: Repeated root */
    printf("Test 2: x^2 - 6x + 9 = 0  (perfect square)\n");
    findRoots(1, -6, 9);
    printf("\n");

    /* Test Case 3: Complex roots */
    printf("Test 3: 2x^2 + 3x + 5 = 0\n");
    findRoots(2, 3, 5);
    printf("\n");

    /* Test Case 4: Harder equation */
    printf("Test 4: 5x^2 - 13x - 6 = 0\n");
    findRoots(5, -13, -6);
    printf("\n");

    /* Test Case 5: User input */
    float a, b, c;
    printf("------------------------------------------\n");
    printf("Enter your own quadratic: ax^2 + bx + c = 0\n");
    printf("Enter a: "); scanf("%f", &a);
    printf("Enter b: "); scanf("%f", &b);
    printf("Enter c: "); scanf("%f", &c);
    printf("\nYour equation: %.2fx^2 + %.2fx + %.2f = 0\n", a, b, c);
    findRoots(a, b, c);

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === QUADRATIC POLYNOMIAL ROOT FINDER ===
 *     Equation form: ax^2 + bx + c = 0
 *
 * Test 1: 3x^2 - 10x + 8 = 0
 *   Discriminant D = b^2 - 4ac = -10.00^2 - 4*3.00*8.00 = 4.0000
 *   D > 0 --> Two distinct real roots:
 *     x1 = (10.00 + sqrt(4.0000)) / (2*3.00) = 2.000000
 *     x2 = (10.00 - sqrt(4.0000)) / (2*3.00) = 1.333333
 *
 * Test 2: x^2 - 6x + 9 = 0  (perfect square)
 *   Discriminant D = b^2 - 4ac = -6.00^2 - 4*1.00*9.00 = 0.0000
 *   D = 0 --> Two equal (repeated) real roots:
 *     x1 = x2 = 3.000000
 *
 * Test 3: 2x^2 + 3x + 5 = 0
 *   Discriminant D = b^2 - 4ac = 3.00^2 - 4*2.00*5.00 = -31.0000
 *   D < 0 --> Two complex (imaginary) roots:
 *     x1 = -0.7500 + 1.3919i
 *     x2 = -0.7500 - 1.3919i
 *
 * Test 4: 5x^2 - 13x - 6 = 0
 *   Discriminant D = b^2 - 4ac = -13.00^2 - 4*5.00*-6.00 = 289.0000
 *   D > 0 --> Two distinct real roots:
 *     x1 = 3.000000
 *     x2 = -0.400000
 *
 * ============================================================
 * HOW IT WORKS:
 * ============================================================
 * QUADRATIC FORMULA: x = (-b ± √(b²-4ac)) / (2a)
 *
 * THE DISCRIMINANT (D = b²-4ac) tells us about roots:
 *   D > 0: sqrt(D) is real → ±sqrt gives two DIFFERENT values → 2 real roots
 *   D = 0: sqrt(D) = 0 → ± gives same value → 1 repeated root
 *   D < 0: sqrt of negative → imaginary → 2 complex roots
 *
 * VERIFICATION — Test 1 (3x²-10x+8=0, roots 2 and 1.333):
 *   Substitute x=2: 3*4 - 10*2 + 8 = 12 - 20 + 8 = 0 ✓
 *   Substitute x=4/3: 3*(16/9) - 10*(4/3) + 8
 *               = 48/9 - 40/3 + 8 = 16/3 - 40/3 + 24/3 = 0/3 = 0 ✓
 *
 * LIBRARY FUNCTION: sqrt() from <math.h>
 *   Computes the square root of a non-negative number.
 *   For complex roots, we use sqrt(-D) since -D is positive when D < 0.
 * ============================================================
 */
