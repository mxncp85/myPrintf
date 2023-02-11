/*
** EPITECH PROJECT, 2022
** CPOOLDAY07
** File description:
** Concatenates strings
*/

int my_strlen(char const *str);

char *my_strcat (char *dest , char const *src)
{
    int len1 = my_strlen(dest);
    int len2 = my_strlen(src);

    for (int i = 0; i < len2; i++) {
        dest[len1 + i] = src[i];
    }
    dest[len1 + len2] = '\0';
    return dest;
}
