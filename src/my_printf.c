/*
** EPITECH PROJECT, 2022
** B-CPE-101-NAN-1-1-myprintf-maxence.perronie
** File description:
** my_printf main function
*/

#include "../include/my.h"
#include <stdarg.h>

int text_parse (char const* format, ...);

int my_printf(char const *format, ...)
{
    va_list args;
    va_start(args, format);
    return text_parse(format, args);
}
