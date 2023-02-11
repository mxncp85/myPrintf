/*
** EPITECH PROJECT, 2022
** B-CPE-101-NAN-1-1-myprintf-maxence.perronie
** File description:
** File of params getters
*/

#include "../include/my.h"

int conversion_end(char format_char);
int get_nbr(char const* format);
int is_number(char c);

int get_params (char const* format, int param)
{
    int param_cnt = 0;
    int i = 0;

    while (conversion_end(format[i]) != 1) {
        i++;
    }
    if ((param == '.') && (format[i] == 'e' || format[i] == 'E'
    || format[i] == 'f')) {
        param_cnt = 6;
    }
    i = 0;
    while (conversion_end(format[i]) != 1) {
        if (format[i] == param) {
            param_cnt = get_nbr(&format[i + 1]);
        }
        i++;
    }
    return param_cnt;
}

int get_zeros (char const* format, char param, char flag)
{
    int param_cnt = 0;
    int i = 0;
    while (conversion_end(format[i]) != 1) {
        if ((format[i] == param) && (is_number(format[i - 1]) == 0 ||
        format[i - 1] == '%')) {
            param_cnt = get_nbr(&format[i + 1]);
            break;
        }
        i++;
    }
    return param_cnt;
}

int get_symbol (char const* format, char symbol)
{
    int i = 0;
    int val = 0;

    while (conversion_end(format[i]) != 1) {
        if (format[i] == symbol) {
            val = 1;
            break;
        }
        i++;
    }
    return val;
}

int get_fw (char const* format)
{
    int i = 0;
    int fw = 0;
    while (conversion_end(format[i]) != 1) {
        if (is_number(format[i]) == 1 && format[i - 1] != '.') {
            fw = get_nbr(&format[i]);
            break;
        }
        i++;
    }
    return fw;
}
