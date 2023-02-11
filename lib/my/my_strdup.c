/*
** EPITECH PROJECT, 2022
** CPOOLDAY08
** File description:
** Write a function that allocates memory and
** copies the string given as argument in it
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *str)
{
    int len = my_strlen(str);
    char *str2 = malloc(sizeof(char) * len);

    my_strcpy(str2, str);
    return str2;
}
