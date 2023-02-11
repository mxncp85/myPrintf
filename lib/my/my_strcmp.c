/*
** EPITECH PROJECT, 2022
** CPOOLDAY06
** File description:
** Compares two strings
*/

int my_strlen(char const *str);

int comparisons(int len1, int len2, int diff);

int my_strcmp(char const *s1, char const *s2)
{
    int diff = 0;
    int i = 0;
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    while (i <= len1 - 1) {
        diff = diff + (s1[i] - s2[i]);
        i++;
    }
    return comparisons(len1, len2, diff);
}
