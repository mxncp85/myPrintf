/*
** EPITECH PROJECT, 2022
** CPOOLDAY06
** File description:
** Copies the string into another string
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i ; src[i] != '\0' ; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
