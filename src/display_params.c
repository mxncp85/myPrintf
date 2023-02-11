/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** display_params
*/

#include <stdarg.h>
#include "../include/my.h"

int get_symbol (char const* format, char symbol);
int get_params (char const* format, int param);
int my_putchar_special(char c, int croisi);
int digit_counter(int nb);
int conv_spec_finder (char const *format);
int get_fw (char const* format);
int get_zeros (char const* format, char param, char flag);
int precision_specified (char const *format);

int display_space (int printed_chars, char const *format, int croisi)
{
    char c = ' ';
    char c_spec = conv_spec_finder(&format[0]);
    int zero = get_zeros(&format[0], '0', c_spec);
    int fw = get_fw(&format[0]);

    if (fw == 0 && zero > 0) {
        fw = zero;
        c = '0';
    }
    if ((croisi == 1) || ((precision_specified(&format[0]))
    && (c_spec == 'd' || c_spec == 'i' || c_spec == 'x' ||
    c_spec == 'X' || c_spec == 'o' || c_spec == 'u')) ||
    (c_spec == 's')) {
        c = ' ';
    }
    while (printed_chars < fw) {
        my_putchar(c);
        printed_chars++;
    }
    return printed_chars;
}

int display_plus (char const* format, char c_spec, va_list args, int croisi)
{
    int plus = get_symbol(&format[0], '+');
    va_list args2;
    va_copy(args2, args);
    int nb = va_arg(args2, int);

    if ((plus == 1 && nb > 0) && (c_spec == 'd' ||
    c_spec == 'i' || c_spec == 'f')) {
        my_putchar_special('+', croisi);
        return plus;
    }
    return 0;
}

int display_diez (char const *format, char c_spec, va_list args, int croisi)
{
    int diez = get_symbol(&format[0], '#');
    va_list args2;
    va_copy(args2, args);
    int nb = va_arg(args2, int);
    int prec = get_params(&format[0], '.');

    if (diez == 1) {
        if (c_spec == 'o' && nb != 0 && digit_counter(nb) >= prec) {
            my_putchar_special('0', croisi);
            return 1;
        }
        if ((c_spec == 'x' || c_spec == 'X') && (nb != 0)) {
            my_putchar_special('0', croisi);
            my_putchar_special(c_spec, croisi);
            return 2;
        }
    }
    return 0;
}

int display_blank (char const *format, va_list args, int fw, int croisi)
{
    va_list args2;
    va_copy(args2, args);
    int nb = va_arg(args2, double);
    int space = get_symbol(&format[0], 32);
    int plus = get_symbol(&format[0], '+');
    int c_spec = conv_spec_finder(&format[0]);

    if (plus == 1) {
        space = 0;
    }
    if ((nb >= 0) && (space == 1) && (c_spec == 'i'
    || c_spec == 'd' || c_spec == 'e' || c_spec == 'E')) {
        my_putchar_special(' ', croisi);
        return space;
    }
    return 0;
}
