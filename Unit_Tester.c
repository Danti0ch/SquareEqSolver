/**
 * \file
*   \brief Файл, хранящий тесты, ответы на тесты и функцию юнит тестирования
*/

#include "stdio.h"
#include "main.h"
#include "assert.h"

/// ограничение на количество тестов
static const int MAX_TESTS = 500;

/// количество аргументов(входных + выходных переменных) в одном тесте
static const int N_TEST_ARGS = 6;

/// количество аргументов в ответе на тест
static const int N_ANSWER_ARGS = 3;

/**
 * Функция, получающее решение теста через функции файла Square.c и сравнивающая его с правильным
 * \param ind номер теста
 * \return 1, если тест успешно пройден. 0 в противном случае
 */
static enum TestStatus Test(int ind);
/**
 * Функция, считывает условие тестов квадратных уравнений(коэффициенты) и ответы на тесты. Записывает
 * условия в массив tests
 * @return количество считанных тестов
 */
static int GetTests();

///индексы элементов теста
enum TestArgsCode {
    PAR1_TEST_CODE = 0,
    PAR2_TEST_CODE = 1,
    PAR3_TEST_CODE = 2,
    N_ROOTS_TEST_CODE = 3,
    FIRST_ROOT_TEST_CODE = 4,
    SECOND_ROOT_TEST_CODE = 5
};

/// индексы элементов ответа на тест
enum AnsArgsCode {
    N_ROOTS_ANS_CODE = 0,
    FIRST_ROOT_ANS_CODE = 1,
    SECOND_ROOT_ANS_CODE = 2
};
/// массив для хранения условий тестов вида (par1 par2 par3 nRoots root1 root2)
double tests[MAX_TESTS][N_TEST_ARGS];
/// массив для хранения ответов функций SolveSquare.c на тесты. Ответы имеют вид (nRoots root1 root2)
double answers[MAX_TESTS][N_ANSWER_ARGS];

void Testing(void) {

    int nTests = GetTests();
    int passed_tests_counter = 0;

    for (int i = 0; i < nTests; i++) {
        if (Test(i)) {
            printf("test %d passed\n", i + 1);
            passed_tests_counter++;
        } else
            printf("*   test %d failed\n"
                   "*   Expected: nRoots = %lf | x1 = %lf | x2 = %lf\n"
                   "*   Found:    nRoots = %lf | x1 = %lf | x2 = %lf\n", i + 1,
                   tests[i][N_ROOTS_TEST_CODE],
                   tests[i][FIRST_ROOT_TEST_CODE],
                   tests[i][SECOND_ROOT_TEST_CODE],
                   answers[i][N_ROOTS_ANS_CODE],
                   answers[i][FIRST_ROOT_ANS_CODE],
                   answers[i][SECOND_ROOT_ANS_CODE]
            );
    }

    printf("%d / %d passed\n", passed_tests_counter, nTests);
}

static enum TestStatus Test(int ind) {
    double x1 = NAN, x2 = NAN;
    double a = tests[ind][PAR1_TEST_CODE], b = tests[ind][PAR2_TEST_CODE], c = tests[ind][PAR3_TEST_CODE];

    int rnRoots = (int) tests[ind][N_ROOTS_TEST_CODE];
    double rx1 = tests[ind][FIRST_ROOT_TEST_CODE];
    double rx2 = tests[ind][SECOND_ROOT_TEST_CODE];

    int nRoots = answers[ind][N_ROOTS_ANS_CODE] = SolveSqrEq(a, b, c, &x1, &x2);

    if (IsEqual(x1, rx2) && IsEqual(x2, rx1)) {
        double temple = x1;
        x1 = x2;
        x2 = temple;
    }

    answers[ind][FIRST_ROOT_ANS_CODE] = x1;
    answers[ind][SECOND_ROOT_ANS_CODE] = x2;


    if (nRoots == rnRoots && nRoots < ONE_ROOT)
        return PASSED;

    else if (nRoots == rnRoots && (IsEqual(x1, rx1) && IsEqual(x2, rx2))) {
        return PASSED;
    } else
        return FAILED;
}

static int GetTests() {
    FILE *fp = fopen("tests.txt", "r");
    assert(fp != NULL);

    int nTests = 0;
    while (fscanf(fp, "%lf %lf %lf %lf %lf %lf",
                  &tests[nTests][PAR1_TEST_CODE],
                  &tests[nTests][PAR2_TEST_CODE],
                  &tests[nTests][PAR3_TEST_CODE],
                  &tests[nTests][N_ROOTS_TEST_CODE],
                  &tests[nTests][FIRST_ROOT_TEST_CODE],
                  &tests[nTests][SECOND_ROOT_TEST_CODE]) == N_TEST_ARGS) {
        nTests++;
        assert(nTests < MAX_TESTS);
    }
    assert(nTests != 0);

    return nTests;
}