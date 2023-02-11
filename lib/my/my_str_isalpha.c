/*
** EPITECH PROJECT, 2022
** CPOOLDAY04
** File description:
** Capitalizez the first letter of each word
*/

int my_str_isalpha(char const *str)
{
    int cnt = 0;
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) {
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
