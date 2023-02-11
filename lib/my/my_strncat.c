/*
** EPITECH PROJECT, 2022
** CPOOLDAY07
** File description:
** Concatenates n-characters of another string
*/

int my_strlen(char const *str);

char *my_strncat (char *dest , char const *src, int n)
{
    int len1 = my_strlen(dest);
    int len2 = my_strlen(src);
    int i;

    for (i = 0; i < len2 && i < n; i++) {
        dest[len1 + i] = src[i];
    }
    dest[len1 + i] = '\0';
    return dest;
}
