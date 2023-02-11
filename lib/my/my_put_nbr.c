/*
** EPITECH PROJECT, 2022
** CPOOLDAY03
** File description:
** Displays the number given as a parameter.
** It must be able to display all the possible value
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
    long nbl = nb;
    int digits = 1;
    int i = 0;

    if (nbl < 0) {
        my_putchar('-');
        nbl = nbl * -1;
        i++;
    }
    while (nbl / digits >= 10) {
        digits = digits * 10;
    }
    while (digits >= 1) {
        my_putchar((nbl / digits) % 10 + 48);
        i++;
        digits = digits / 10;
    }
    return i;
}