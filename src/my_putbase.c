/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Puts base in binary, hexadec, or octadec
*/

#include "../include/my.h"
#include <stdarg.h>

int my_ascii_isletter(int a);
int my_putchar_special(char c, int croisi);
char conv_spec_finder (char const *format);

int my_putbase_putprec(int digit_count, int prec, int croisi)
{
    int printed_chars = 0;

    while (digit_count < prec) {
        my_putchar_special('0', croisi);
        digit_count++;
        printed_chars++;
    }
    return printed_chars;
}

int put_binary(va_list args)
{
    int binary_digits[32];
    int i = 0;
    unsigned int nb = va_arg(args, unsigned int);
    int printed_chars;

    while (nb != 0) {
        binary_digits[i] = nb % 2;
        nb = nb / 2;
        i++;
    }
    printed_chars = i;
    while (i > 0) {
        i--;
        my_put_nbr(binary_digits[i]);
    }
    return printed_chars;
}

void display_hexa(int ascii_code, int croisi, const char* format)
{
    int casing = 0;
    char flag = conv_spec_finder(&format[0]);

    if (flag >= 'a' && flag <= 'z') {
        casing = 32;
    }
    if (my_ascii_isletter(ascii_code) == 1 && croisi == 1) {
        my_putchar(ascii_code + casing);
    } else if (croisi == 1) {
        my_put_nbr(ascii_code);
    }
}

int put_hexadec(va_list arg, int prec, int croisi, const char *format)
{
    int hexa_val[32];
    int i = 0;
    int nb = va_arg(arg, int);
    int printed_chars = 0;
    if (nb == 0) {
        my_putchar_special('0', croisi);
        return 0;
    }
    for (nb ; nb != 0 ; nb /= 16 , i++, printed_chars++) {
        if ((nb % 16 >= 10) && (nb % 16 <= 15)) {
            hexa_val[i] = 65 + (nb % 16 - 10);
        } else {
            hexa_val[i] = nb % 16;
        }
    }
    printed_chars += my_putbase_putprec(i, prec, croisi);
    for (i; i > 0; i--) {
        display_hexa(hexa_val[i - 1], croisi, format);
    }
    return printed_chars;
}

int put_octadec(va_list arg, int prec, int croisi)
{
    int nb = va_arg(arg, int);
    int octa_val[32];
    int i = 0;
    int printed_chars;

    while (nb != 0) {
        octa_val[i] = nb % 8;
        nb = nb / 8;
        i++;
    }
    printed_chars = i;
    printed_chars += my_putbase_putprec(i, prec, croisi);
    while (i > 0) {
        i--;
        my_putchar_special(octa_val[i] + '0', croisi);
    }
    return printed_chars;
}
