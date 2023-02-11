/*
** EPITECH PROJECT, 2022
** CPOOLDAY06
** File description:
** Compares two strings
*/

int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int diff = 0;
    int i = 0;
    while ((i <= n - 1) && (i <= my_strlen(s1) - 1)) {
        diff = diff + (s1[i] - s2[i]);
        i++;
    }
    return diff;
}
