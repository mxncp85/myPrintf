/*
** EPITECH PROJECT, 2022
** CPOOLDAY06
** File description:
** Reverses the string
*/

int my_strlen(char const *str);

char rev_char(char *a, char *b);

char *my_revstr(char *str)
{
    int strlen = my_strlen(str) - 1;

    for (int cnt = 0; cnt < strlen; cnt++) {
        rev_char(&str[cnt], &str[strlen]);
        strlen--;
    }
    return &str[0];
}
