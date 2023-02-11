/*
** EPITECH PROJECT, 2022
** f flag
** File description:
** convert a double into a decimal
*/

#include "../include/my.h"
#include <stdlib.h>
#include <stdarg.h>

int my_put_nbr2(va_list arg, int prec, int croisi);
int my_put_float(va_list arg, int precision, int croisi);

int case_precision_missing(va_list arg, int croisi)
{
    int i = my_put_float(arg, 6, croisi);
    return i;
}

int case_precision(va_list arg, int precision, int croisi)
{
    int i = my_put_float(arg, precision, croisi);
    return i;
}

int case_precision_zero(va_list arg, int croisi)
{
    int i = my_put_nbr2(arg, 0, croisi);
    return i;
}

int my_f_flag(va_list arg, int precision, int croisi )
{
    double decimal_precision = (double) my_pow(10, precision);
    int nb_char = 0;

    if (precision == 'n') {
        nb_char = case_precision_missing(arg, croisi);
        return nb_char;
    }
    if (precision == 0) {
        nb_char = case_precision_zero(arg, croisi);
        return nb_char;
    }
    if (precision > 0) {
        nb_char = case_precision(arg, precision, croisi);
        return nb_char;
    }
}
