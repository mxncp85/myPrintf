/*
** EPITECH PROJECT, 2022
** p flag
** File description:
** print a pointer into hexa
*/

#include "../include/my.h"
#include <stdarg.h>

void my_p_flag(va_list args)
{
    void *pointer = va_arg(args, void*);
    long long pointer_out = (long long) pointer;
    put_hexadec(pointer_out, 0, 1);
}
