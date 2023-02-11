/*
** EPITECH PROJECT, 2022
** my put float
** File description:
** display a float
*/

#include <stdlib.h>
#include <stdarg.h>
#include "../include/my.h"

int my_putchar_special(char c, int croisi);

int my_put_nbr_special(int nb, int croisi)
{
    long nbl = nb;
    int digits = 1;
    int i = 0;

    if (nbl < 0) {
        my_putchar_special('-', croisi);
        nbl = nbl * -1;
        i++;
    }
    while (nbl / digits >= 10) {
        digits = digits * 10;
    }
    while (digits >= 1) {
        my_putchar_special((nbl / digits) % 10 + 48, croisi);
        i++;
        digits = digits / 10;
    }
    return i;
}

int my_putnbr_base_long(long nbr, char *base, int precision, int croisi)
{
    int i = 0;
    int size;
    long nb;
    char result[precision];

    size = my_strlen(base);
    while (i < precision) {
        nb = nbr;
        nbr = nbr / size;
        result[i] = base[nb % size];
        i++;
    }
    nb = i;
    while (i >= 0) {
        my_putchar_special(result[i - 1], croisi);
        i--;
    }
    return nb;
}

int my_put_float(va_list arg, int precision, int croisi)
{
    long dec;
    long ent;
    double dec2;
    int i = 0;
    double nbr = va_arg(arg, double);

    ent = nbr;
    dec = nbr * (float) my_pow(10, precision - 1);
    dec -= ent * my_pow(10, precision - 1);
    dec2 = (double)dec;
    if (dec2 < 0)
        dec2 = dec2 * (-1);
    i += my_put_nbr_special((int) nbr, croisi);
    i++;
    my_putchar_special('.', croisi);
    i += my_putnbr_base_long((long)dec2, "0123456789", precision, croisi);
    return i;
}
