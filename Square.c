#include "math.h"
#include "assert.h"
#include "stdio.h"
#include "main.h"

int SolveSqrEq(const double a, const double b, const double c,
               double *x1, double *x2) { /* ax^2 + bx + c = 0*/
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    double D = b * b - 4 * a * c;
    if (D < (-EPS))
        return NO_ROOTS;

    if (CloseToZero(a)) {
        int nRoots = SolveLinEq(b, c, x1);
        (*x2) = (*x1);
        return nRoots;
    }

    (*x1) = (-b + sqrt(D)) / (2 * a);
    (*x2) = (-b - sqrt(D)) / (2 * a);

    if (CloseToZero((*x1) - (*x2)))
        return ONE_ROOT;
    else
        return TWO_ROOTS;
}

int SolveLinEq(const double a, const double b, double *x) { /* ax + b = 0*/
    assert(x != NULL);

    assert(isfinite(a));
    assert(isfinite(b));

    if (CloseToZero(a)) {
        if (CloseToZero(b))
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
        while (getchar() != '\n');
        printf("Enter parameters in right form(a b c):");
    }
}

void PrintResult(int nRoots, double x1, double x2) {
    assert(isfinite(x1));
    assert(isfinite(x2));

    if(CloseToZero(x1))
        x1 = 0.0;
    if(CloseToZero(x2))
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

int CloseToZero(double val) {
    return fabs(val) < EPS;
}