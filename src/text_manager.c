/*
** EPITECH PROJECT, 2022
** B-CPE-101-NAN-1-1-myprintf-maxence.perronie
** File description:
** Parses the text
*/

#include <stdarg.h>
#include "../include/my.h"

int get_symbol (char const* format, char symbol);
int get_fw (char const* format, int printed_chars);
int conv_spec_manager(const char *format, va_list args, int croisi);
int display_blank (char const *format, va_list args, int fw, int croisi);
int display_diez (char const *format, char c_spec, va_list args, int croisi);
int display_plus (char const* format, char c_spec, va_list args, int croisi);
int display_space (int printed_chars, char const *format, int croisi);


int conversion_end(char format_char)
{
    char conversion_spec_end [] = {'d', 'i', 'o', 'x', 'X', 'u', 'c'
    , 's', 'f', 'e', 'E', 'g', 'G', 'p', 'n', '%', 'S', 'b'};
    int i = 0;

    while (conversion_spec_end[i] != 0) {
        if (format_char == conversion_spec_end[i]) {
            return 1;
        }
        i++;
    }
}

int conv_spec_finder (char const *format)
{
    int i = 0;
    while (conversion_end(format[i]) != 1) {
        i++;
    }
    return format[i];
}

int param_manager (char const *format, char c_spec, va_list args, int croisi)
{
    int printed_chars = 0;
    va_list args2;
    va_copy(args2, args);
    int field_width = get_fw(&format[0], printed_chars);

    printed_chars += display_diez(format, c_spec, args, croisi);
    printed_chars += display_plus(format, c_spec, args, croisi);
    printed_chars += display_blank(format, args, field_width, croisi);
    return printed_chars;
}

int flags_parser (char const* format, va_list args)
{
    char conversion_flag = conv_spec_finder(&format[0]);
    int printed_chars = 0;
    int croisi = get_symbol(&format[0], '-');
    va_list args2;
    va_copy(args2, args);

    if (conversion_flag == '%') {
        my_putchar('%');
        return 0;
    }
    if (croisi == 0) {
        printed_chars += param_manager(format, conversion_flag, args, croisi);
        printed_chars += conv_spec_manager(format, args2, croisi);
        display_space(printed_chars, format, croisi);
    }
    printed_chars += param_manager(format, conversion_flag, args, 1);
            printed_chars += conv_spec_manager(format, args, 1);
    if (croisi == 1)
        display_space(printed_chars, format, croisi);
    return printed_chars;
}

int text_parse (char const* format, va_list args)
{
    int i = 0;
    int loop = 0;

    while (format[i] != '\0') {
        if (format[i] == '%') {
            flags_parser(&format[i + 1], args);
            loop = 1;
            i++;
        }
        while (loop == 1 && conversion_end(format[i]) != 1) {
            i++;
        }
        if (loop == 0) {
            my_putchar(format[i]);
        }
        loop = 0;
        i++;
    }
    va_end(args);
    return 0;
}
