#include "stdio.h"
#include "main.h"

static const double equations[][N_INPUT_ELEMENTS] = {{1,        2,        1},
                                                     {1,        -2,       1},
                                                     {1e10,     -2e10,    1e10},
                                                     {0.000001, 0.000123, 0.000012},
                                                     {0,        0,        0},
                                                     {0,        0,        100},
                                                     {0,        -80,      0},
                                                     {123,      0,        0},
                                                     {12,       -24,      0},
                                                     {1,        0,        500},
                                                     {0,        1e15,     -123e12},
                                                     {1,        1,        0}};

static const double solutions[][N_OUTPUT_ELEMENTS] = {{1,  -1,                  -1},
                                                      {1,  1,                   1},
                                                      {1,  1,                   1},
                                                      {2,  -122.90236151810451, -0.09763848189549935},
                                                      {-1, 0,                   0},
                                                      {0,  0,                   0},
                                                      {1,  0,                   0},
                                                      {1,  0,                   0},
                                                      {2,  0,                   2},
                                                      {0,  0,                   0},
                                                      {1,  0.123,               0.123},
                                                      {2,  0,                   -1}};

static int Test(int ind);

void Testing(void) {

    int nTests = (int) (sizeof(equations) / sizeof(equations[0]));
    int passed_tests_counter = 0;

    for (int i = 0; i < nTests; i++) {
        if (Test(i)) {
            printf("test %d passed\n", i + 1);
            passed_tests_counter++;
        } else
            printf("test %d failed\n"
                   "Expected %d %lf %lf\n"
                   "Got %d %lf %lf\n", i + 1);
    }

    printf("%d / %d passed\n", passed_tests_counter, nTests);
}

static int Test(int ind) {
    double x1, x2;
    double a = equations[ind][0], b = equations[ind][1], c = equations[ind][2];

    int rnRoots = (int) solutions[ind][0];
    double rx1 = solutions[ind][1];
    double rx2 = solutions[ind][2];

    int nRoots = SolveSqrEq(a, b, c, &x1, &x2);
    if (nRoots == rnRoots && nRoots < 1)
        return PASSED;

    else if (nRoots == rnRoots &&
             (CloseToZero(x1 - rx1) && CloseToZero(x2 - rx2) ||
              (CloseToZero(x1 - rx2) && CloseToZero(x2 - rx1)))) {
        return PASSED;
    } else
        return FAILED;
}