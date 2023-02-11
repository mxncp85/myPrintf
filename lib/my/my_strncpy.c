/*
** EPITECH PROJECT, 2022
** CPOOLDAY06
** File description:
** Copies n characters of a string into another string
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int length = my_strlen(dest);
    int i;
    for ( i = 0 ; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return dest;
}
