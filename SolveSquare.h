/**
* \file
*   \brief Заголовочный файл, в котором находятся константы и обьявления функций, определенных в SolveSquare.c
*
*/

#ifndef SQUAREEQSOLVER_SOLVESQUARE_H
#define SQUAREEQSOLVER_SOLVESQUARE_H

#include "math.h"

/// константа, обозначающая минимальное число типа double
const double EPS = 1e-8;

/// Варианты количества корней
enum NumberRoots {
    INF_ROOTS = -1, ///< бесконечность
    NO_ROOTS  = 0,  ///< 0
    ONE_ROOT  = 1,  ///< 1
    TWO_ROOTS = 2   ///< 2
};

/**
*   Основная функция для решения уравнений вида ax^2 + bx + c = 0,
 *   решения записываются в аргументы x1, x2. Если корень один, то его значение
 *   записывается в обе переменные. Если корней нет, то x1 и x2 содержат NAN
 *
 *   \param a, b, c коэффициенты квадратного уравнения
 *   \param x1, x2 корни
 *
 *   \return Возвращаемое значение - количество корней уравнения или -1, если количество корней - бесконечность.
*/
enum NumberRoots SolveSqrEq(double a, double b, double c, double *x1, double *x2);

/**
*   Функция для решения уравнений вида ax + b = 0,
 *   решение записывается в аргумент x.
 *
 *   \param a, b коэффициенты линейного уравнения
 *   \param x переменная для хранения корня
 *
 *   \return Возвращаемое значение - количество корней уравнения или -1, если количество корней - бесконечность
*/
enum NumberRoots SolveLinEq(double a, double b, double *x);

/**
*   Функция для ввода коэффициентов квадратного уравнения с консоли. Если ввод является некоректным(не является строкой вида 'a b c', где a, b, c -
 *   числа типа double), то выводится соответсвующее предупреждение, до тех пор, пока пользователь не введет
 *   коэффициенты в требуемой форме.
 *
 *   \param a, b, c коэффициенты, в которые нужно записать данные
*/
void GetParams(double *a, double *b, double *c);

/**
*   Функция для вывода результата решения квадратного уравнения
 *
 *   \param nRoots количество корней
 *   \param x1, x2 корни
*/
void PrintResult(enum NumberRoots nRoots, double x1, double x2);

/**
*   Функция для проверки числа типа double соответствия нулю
 *   \param val1, val2 - числа double, которые надо сравнить
 *
 *   \return 1, если val1 == val2. Иначе 0
*/
inline int IsEqual(double val1, double val2) {
    if(isnan(val1) && isnan(val2))
        return 1;

    return fabs(val1 - val2) < EPS;
}

#endif
