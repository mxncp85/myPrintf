/*
** EPITECH PROJECT, 2022
** B-CPE-101-NAN-1-1-myprintf-maxence.perronie
** File description:
** e flag for printf
*/

#include "../include/my.h"
#include <stdarg.h>

char conv_spec_finder (char const *format);
int digit_counter(int nb);
int my_putchar_special(char c, int croisi);
int get_symbol (char const* format, char symbol);

int approx(double nb, int *digit_arr, int prec)
{
    int i = 0;

    while (digit_arr[i] != '\0') {
        if ((digit_arr[i] == 5 && digit_arr[i - 1] >= 5) && (prec == 0)) {
            return 1;
        }
        if ((digit_arr[i - 1] > 5) || (digit_arr[i - 1] == 5 &&
        digit_arr[i - 2] != 0)) {
            return 1;
        }
        if (digit_arr[i - 1] < 5) {
            return 0;
        }
        i++;
    }
}

int double_to_int(double nb, int plus, int croisi)
{
    int dec;
    int digits;

    if (nb > 0 && plus == 1) {
        my_putchar_special('+', croisi);
    }
    if (nb < 0) {
        my_putchar_special('-', croisi);
        nb *= -1;
    }
    dec = nb;
    digits = digit_counter(dec);
    if (digits < 7) {
        dec = nb * (my_pow(10, 6 - digits));
    }
    return dec;
}

int expo_display(int croisi, double nb, const char *format, int digits)
{
    int printed_chars = 0;
    my_putchar_special(conv_spec_finder(&format[0]), croisi);
    my_putchar_special('+', croisi);
    if (nb == 0) {
        my_putchar_special('0',croisi);
        my_putchar_special('0',croisi);
        return printed_chars;
    }
    if (digits - 1 < 10) {
        my_putchar_special('0', croisi);
    }
    return printed_chars;
}

int end_display(double nb, const char *format, int prec, int croisi)
{
    int dec = nb;
    int digits = digit_counter(dec);
    int diez = get_symbol(&format[0], '#');
    int printed_chars = 4;
    if (prec > 0) {
        printed_chars++;
    }
    if (diez == 1 && prec == 0) {
        my_putchar_special('.',croisi);
        printed_chars++;
    }
    printed_chars += expo_display(croisi, nb, format, digits);
    my_putchar_special(digits - 1 + '0', croisi);
    return printed_chars;
}

int my_e_flag(va_list arg, int prec,int croisi, const char *format)
{
    int i = 0;
    int plus = get_symbol(&format[0], '+');
    double nb = va_arg(arg, double);
    int nb2 = double_to_int(nb, plus, croisi);
    int digit_arr[8];
    while (i < 7) {
        digit_arr[i] = nb2 % 10;
        i++;
        nb2 /= 10;
    }
    digit_arr[6 - prec] += approx(nb, &digit_arr[6 - prec], prec);
    i--;
    while (i >= 6 - prec) {
        my_putchar_special(digit_arr[i] + '0', croisi);
        if ((i == 6) && (prec != 0)) {
            my_putchar_special('.', croisi);
        }
        i--;
    }
    return prec + end_display(nb, format, prec, croisi) + 1;
}
