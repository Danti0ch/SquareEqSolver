/**
*   \file
*   \brief Файл, хранящий тесты, ответы на тесты и функцию юнит тестирования
*/

#include "stdio.h"
#include "UnitTester.h"
#include "SolveSquare.h"
#include "assert.h"

enum TestStatus {
    FAILED = 0,
    PASSED = 1
};

/**
 * Функция, получающее решение теста через функции файла Square.c и сравнивающая его с правильным
 * \param ind номер теста
 * \return 1, если тест успешно пройден. 0 в противном случае
 */
static enum TestStatus Test(double a, double b, double c, int rnRoots, double rx1, double rx2, int *nRoots, double *x1, double *x2);

void Testing(void) {
    FILE *fp = fopen("tests.txt", "r");
    assert(fp != NULL);

    int passed_tests_counter = 0;
    int nTests = 0;
    double a = NAN, b = NAN, c = NAN, rx1 = NAN, rx2 = NAN, x1 = NAN, x2 = NAN;

    int rnRoots = 0, nRoots = 0;

    for (; fscanf(fp, "%lf %lf %lf %d %lf %lf", &a, &b, &c, &rnRoots, &rx1, &rx2) == 6; nTests++) {

        if (Test(a, b, c, rnRoots, rx1, rx2, &nRoots, &x1, &x2)) {
            printf("test %d passed\n", nTests + 1);
            passed_tests_counter++;
        }
        else
            printf("*   test %d failed\n"
                   "*   Parameters:  a = %lf | b = %lf | c = %lf\n"
                   "*   Expected:    nRoots = %d | x1 = %lf | x2 = %lf\n"
                   "*   Found:       nRoots = %d | x1 = %lf | x2 = %lf\n", nTests + 1,
                   a, b, c,
                   rnRoots, rx1, rx2,
                   nRoots, x1, x2
            );
    }
    fclose(fp);
    
    assert(nTests != 0);

    printf("%d / %d passed\n", passed_tests_counter, nTests);
}


static enum TestStatus Test(double a, double b, double c, int rnRoots, double rx1, double rx2, int *nRoots, double *x1, double *x2) {

    *nRoots = SolveSqrEq(a, b, c, x1, x2);

    if (IsEqual(*x1, rx2) && IsEqual(*x2, rx1)) {
        double temple = *x1;
        *x1 = *x2;
        *x2 = temple;
    }

    if (*nRoots == rnRoots && *nRoots < ONE_ROOT) {
        return PASSED;
    }
    
    else if (*nRoots == rnRoots && (IsEqual(*x1, rx1) && IsEqual(*x2, rx2))) {
        return PASSED;
    } else
        return FAILED;
}