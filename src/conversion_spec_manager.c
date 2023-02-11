/*
** EPITECH PROJECT, 2022
** B-CPE-101-NAN-1-1-myprintf-maxence.perronie
** File description:
** Manages the distribution of the conversion specifiers
*/


#include "../include/my.h"
#include "../include/printf_structs.h"
#include <stdarg.h>

int put_octadec(va_list arg, int prec);
int put_S_flag(char const *str);
void put_binary(unsigned int nb);
int put_hexadec(va_list arg, int prec);
int get_params (char const* format, char const * param);
int conversion_end(char format_char);
int my_putchar2(va_list arg, int prec, int croisi);
int my_putstr2(va_list arg, int prec, int croisi);
int my_put_nbr2(va_list arg, int prec);
int my_e_flag(va_list arg, int prec, int casing, char const *format);
char conv_spec_finder (char const *format);
void my_p_flag(va_list arg);
int my_f_flag(va_list arg, int precision);

int conv_spec_manager(const char *format, va_list args, int croisi)
{
    int (*function) (va_list arg, int, int, const char*);
    char flag = conv_spec_finder(&format[0]);
    int prec = get_params(&format[0], '.');
    const struct conversion_struct arr [] = {{"c", &my_putchar2},
    {"d", &my_put_nbr2}, {"i", &my_put_nbr2}, {"o", &put_octadec},
    {"s", &my_putstr2}, {"S", &put_S_flag}, {"b", &put_binary},
    {"x", &put_hexadec}, {"X", &put_hexadec}, {"e", &my_e_flag},
    {"E", &my_e_flag}, {"u" , &my_put_nbr2}, {"f", &my_f_flag},
    {"p", &my_p_flag}, 0};
    int i = 0;

    while (arr[i].func_adress != '\0') {
        if (arr[i].symbol[0] == flag) {
            function = arr[i].func_adress;
        }
        i++;
    }
    return function(args, prec, croisi, format);
}
