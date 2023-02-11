/*
** EPITECH PROJECT, 2022
** B-CPE-101-NAN-1-1-myprintf-maxence.perronie
** File description:
** Basic functions but they will take va_list as parameters
*/

#include <stdarg.h>
#include "../include/my.h"

int digit_counter(int nb);
int precision_specified (char const *format);

int my_putchar_special(char c, int croisi)
{
    if (croisi == 1) {
        write(1, &c, 1);
    }
    return 1;
}

int my_putchar2(va_list arg, int prec, int croisi)
{
    char a = va_arg(arg, int);
    return my_putchar_special(a, croisi);
}

int my_putstr2(va_list arg, int prec, int croisi, const char* format)
{
    int i = 0;
    char *str = va_arg(arg, char*);
    if (precision_specified(&format[0]) == 0) {
        prec = my_strlen(str);
    }
    for (i; str[i] != '\0' && i < prec ; i++) {
        my_putchar_special(str[i], croisi);
    }
    return i;
}

int my_put_prec(int prec, long nbl, int croisi)
{
    int digit_nb = digit_counter(nbl);
    int printed_chars = 0;

    while (digit_nb < prec) {
        my_putchar_special('0', croisi);
        digit_nb++;
        printed_chars++;
    }
    return printed_chars;
}

int my_put_nbr2(va_list arg, int prec, int croisi)
{
    long nbl = va_arg(arg, int);
    int digits = 1;
    int printed_chars = 0;

    if (nbl < 0) {
        my_putchar_special('-', croisi);
        nbl = nbl * -1;
        printed_chars++;
    }
    printed_chars += my_put_prec(prec, nbl, croisi);
    while (nbl / digits >= 10) {
        digits = digits * 10;
    }
    while (digits >= 1) {
        my_putchar_special((nbl / digits) % 10 + 48, croisi);
        digits = digits / 10;
        printed_chars++;
    }
    return printed_chars;
}
