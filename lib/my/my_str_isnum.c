/*
** EPITECH PROJECT, 2022
** CPOOLDAY06
** File description:
** Reverses the string
*/

int my_str_isnum(char const *str)
{
    int cnt = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57) {
            cnt++;
        }
        i++;
    }
    if (cnt == i) {
        return 1;
    } else {
        return 0;
    }
}
