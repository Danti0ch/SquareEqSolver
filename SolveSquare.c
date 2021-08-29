/**
*   \file
*   \brief Функции, необходимые для вычисления корней квадратного уравнения
*/

#include "math.h"
#include "stdio.h"
#include "SolveSquare.h"
#include "assert.h"

enum NumberRoots SolveSqrEq(const double a, const double b, const double c,
                            double *x1, double *x2) {
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    double D = b * b - 4 * a * c;
    if (D < 0)
        return NO_ROOTS;

    if (IsEqual(a, 0)) {
        enum NumberRoots nRoots = SolveLinEq(b, c, x1);
        (*x2) = (*x1);

        return nRoots;
    }

    if(IsEqual(D, 0)){
        (*x1) = (*x2) = (-b) / (2 * a);

        return ONE_ROOT;
    }
    else {
        (*x1) = (-b + sqrt(D)) / (2 * a);
        (*x2) = (-b - sqrt(D)) / (2 * a);

        return TWO_ROOTS;
    }
}

enum NumberRoots SolveLinEq(const double a, const double b, double *x) { /* ax + b = 0*/
    assert(x != NULL);

    assert(isfinite(a));
    assert(isfinite(b));

    if (IsEqual(a, 0)) {
        if (IsEqual(b, 0))
            return INF_ROOTS;
        return NO_ROOTS;
    }
    (*x) = (-b) / a;
    return ONE_ROOT;
}

void GetParams(double *a, double *b, double *c) {
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    assert(a != b);
    assert(a != c);
    assert(b != c);

    printf("Enter the parameters values(a b c):");
    while (scanf("%lf %lf %lf", a, b, c) != 3) {

        while (getchar() != '\n')
            ;

        printf("Enter parameters in right form(a b c):");
    }
}

void PrintResult(enum NumberRoots nRoots, double x1, double x2) {
    assert(isfinite(x1) || isnan(x1));
    assert(isfinite(x2) || isnan(x2));

    if (IsEqual(x1, 0))
        x1 = 0.0;
    if (IsEqual(x2, 0))
        x2 = 0.0;

    switch (nRoots) {
        case NO_ROOTS:
            printf("No roots\n");
            break;

        case ONE_ROOT:
            printf("One root: %g\n", x1);
            break;

        case TWO_ROOTS:
            printf("Two roots: %g, %g\n", x1, x2);
            break;

        case INF_ROOTS:
            printf("Infinity roots\n");
            break;
            
        default:
            printf("ERROR\n");
            break;
    }
}