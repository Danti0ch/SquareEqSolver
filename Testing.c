/**
 * \file
*   \brief Файл, хранящий тесты, ответы на тесты и функцию юнит тестирования
*/

#include "stdio.h"
#include "main.h"
/// группа тестов. элемент массива equations - массив параметров квадратного уравнения
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

/// группа ответов на тесты. элемент массива solutions - массив, первый элемент которого - количество корней, а остальные элементы - сами корни
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

/**
 * Функция, проводящая юнит-тестирование. Печатает номера успешно пройденных и
 * проваленных тестов. И общее количество успешных тестов
 */
void Testing(void) {

    int nTests = (int) (sizeof(equations) / sizeof(equations[0]));
    int passed_tests_counter = 0;

    for (int i = 0; i < nTests; i++) {
        if (Test(i)) {
            printf("test %d passed\n", i + 1);
            passed_tests_counter++;
        } else
            printf("test %d failed\n", i + 1);
    }

    printf("%d / %d passed\n", passed_tests_counter, nTests);
}

/**
 * Функция, получающее решение теста через функции файла Square.c и сравнивающая его с правильным
 * \param ind номер теста
 * \return 1, если тест успешно пройден. 0 в противном случае
 */
static int Test(int ind) {
    double x1 = NAN, x2 = NAN;
    double a = equations[ind][0], b = equations[ind][1], c = equations[ind][2];

    int rnRoots = (int) solutions[ind][0];
    double rx1 = solutions[ind][1];
    double rx2 = solutions[ind][2];

    int nRoots = SolveSqrEq(a, b, c, &x1, &x2);
    if (nRoots == rnRoots && nRoots < 1)
        return PASSED;

    else if (nRoots == rnRoots &&
             (IsEqual(x1, rx1) && IsEqual(x2, rx2) ||
              (IsEqual(x1, rx2) && IsEqual(x2, rx1)))) {
        return PASSED;
    } else
        return FAILED;
}