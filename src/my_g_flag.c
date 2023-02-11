/*
** EPITECH PROJECT, 2022
** B-CPE-101-NAN-1-1-myprintf-maxence.perronie
** File description:
** g flag for printf
*/

#include "../include/my.h"
#include <stdarg.h>

void my_g_flag(double nb, int precision)
{
    int exponent = 0;

    if (exponent < (-4) || exponent >= precision) {
        my_e_flag();
    } else {
        my_f_flag(nb, precision);
    }
}
