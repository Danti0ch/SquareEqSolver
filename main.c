#include "stdio.h"
#include "main.h"

#define DEBUG

int main() {
#ifdef DEBUG
    Testing();
#else
    double a = 0.0, b = 0.0, c = 0.0;
    GetParams(&a, &b, &c);

    double x1, x2;
    int nRoots = SolveSqrEq(a, b, c, &x1, &x2);
    PrintResult(nRoots, x1, x2);
#endif
    return 1;
}