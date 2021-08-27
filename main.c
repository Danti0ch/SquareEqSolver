/**
 * \file
 * \brief Основной файл программы. Может работать в режиме работы с пользователем или в режиме юнит-тестирования
 *
 * Вид режима определяется определением макроca DEBUG
 */

#include "main.h"

int main() {
#ifdef DEBUG
    N
    Testing();
#else
    double a = NAN, b = NAN, c = NAN;
    GetParams(&a, &b, &c);

    double x1 = NAN, x2 = NAN;
    enum NumberRoots nRoots = SolveSqrEq(a, b, c, &x1, &x2);
    PrintResult(nRoots, x1, x2);
#endif
    return 1;
}