#ifndef SQR_H
#define SQR_H
#define N_INPUT_ELEMENTS 3
#define N_OUTPUT_ELEMENTS 3

const double EPS = 1e-8;
enum NumberRoots {
    INF_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2
};
enum TestStatus {
    FAILED = 0,
    PASSED = 1
};
int SolveSqrEq(double a, double b, double c, double *x1, double *x2);

int SolveLinEq(double a, double b, double *x);

void GetParams(double *a, double *b, double *c);

void Testing(void);

int CloseToZero(double val);

void PrintResult(int nRoots, double x1, double x2);

#endif