/*
** EPITECH PROJECT, 2022
** CPOOLDAY04
** File description:
** Displays one by one the characters of a string
*/

#include "../include/my.h"
#include <stdarg.h>

int put_octadec_char(char c)
{
    int octa_val[32];
    int i = 0;
    int printed_chars;

    while (c != 0) {
        octa_val[i] = c % 8;
        c = c / 8;
        i++;
    }
    printed_chars = i;
    while (i > 0) {
        i--;
        my_put_nbr(octa_val[i]);
    }
    return printed_chars;
}

int put_S_flag(va_list args, int prec)
{
    char *str = va_arg(args, char*);
    int printed_chars = 0;
    int i = 0;

    for (i; str[i] != '\0' && i < prec ; i++) {
        if ((str[i] < 32) || (str[i] >= 127)) {
            my_putchar('\\');
            printed_chars += put_octadec_char(str[i]);
        } else {
            my_putchar(str[i]);
        }
    }
    return printed_chars + i;
}
