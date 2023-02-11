/*
** EPITECH PROJECT, 2022
** B-CPE-101-NAN-1-1-myprintf-maxence.perronie
** File description:
** Utilty functions
*/

#include "../include/my.h"

int conversion_end(char format_char);

int precision_specified (char const *format)
{
    int i = 0;

    while (conversion_end(format[i]) != 1) {
        if (format[i] == '.') {
            return 1;
        }
        i++;
    }
    return 0;
}

int digit_counter(int nb)
{
    int cnt = 0;

    while (nb != 0) {
        nb /= 10;
        cnt++;
    }
    return cnt;
}

int is_number(char c)
{
    if ((c >= '0') && (c <= '9')) {
        return 1;
    }
    return 0;
}

int get_nbr(char const* format)
{
    int nb = 0;
    int i = 0;
    if (format[0] == '0') {
        return 0;
    }
    while (is_number(format[i]) == 1) {
        nb = nb + format[i] - '0';
        if (is_number(format[i + 1])) {
            nb *= 10;
        }
        i++;
    }
    return nb;
}

int my_ascii_isletter(int a)
{
    if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) {
        return 1;
    }
    return 0;
}
