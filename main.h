/**
* \file
*   \brief Заголовочный файл, в котором находятся обьявления функций, используемых в файлах Square.c и main.c
*
*/
#include "math.h"

#ifndef SQR_H
#define SQR_H

/// константа, обозначающая минимальное число типа double
const double EPS = 1e-8;

/// Варианты количества корней
enum NumberRoots {
    INF_ROOTS = -1, ///< бесконечность
    NO_ROOTS = 0, ///< 0
    ONE_ROOT = 1, ///< 1
    TWO_ROOTS = 2 ///< 2
};

enum TestStatus {
    FAILED = 0,
    PASSED = 1
};

int SolveSqrEq(double a, double b, double c, double *x1, double *x2);

int SolveLinEq(double a, double b, double *x);

void GetParams(double *a, double *b, double *c);

void Testing(void);

int IsEqual(double val1, double val2);

void PrintResult(int nRoots, double x1, double x2);

int GetTests();
#endif