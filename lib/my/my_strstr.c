/*
** EPITECH PROJECT, 2022
** CPOOLDAY06
** File description:
** Finds the first occurence of a substring and returns a pointer
** to the beginning
*/

int my_strlen(char const *str);

char *my_strstr(char *str, char const *to_find)
{
    int len1 = my_strlen(str);
    int len2 = my_strlen(to_find);
    int a = 0;
    if (my_strlen(to_find) == 0) {
        return str;
    }
    for (int i = 0; i <= len1 -1; i++) {
        if (str[i] == to_find[a]) {
            a++;
        } else {
            a = 0;
        }
        if (a == len2 - 1) {
            return &str[i];
        }
    }
    return;
}
