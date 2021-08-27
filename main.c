/**
 * \file
 * \brief Основной файл программы. Может работать в режиме работы с пользователем или в режиме юнит-тестирования
 *
 * Вид режима определяется определением макроca DEBUG
 */

#include "stdio.h"
#include "main.h"

// ввод через файл, если будет время

int main() {
#ifdef DEBUG
    Testing();
#else
    double a = NAN, b = NAN, c = NAN;
    GetParams(&a, &b, &c);

    double x1 = NAN, x2 = NAN;
    int nRoots = SolveSqrEq(a, b, c, &x1, &x2);
    PrintResult(nRoots, x1, x2);
#endif
    return 1;
}