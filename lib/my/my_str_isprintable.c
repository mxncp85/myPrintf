/*
** EPITECH PROJECT, 2022
** CPOOLDAY04
** File description:
** Capitalizez the first letter of each word
*/

int my_str_isprintable(char const *str)
{
    int cnt = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 31) {
            cnt++;
        }
        i++;
    }
    if (cnt == i) {
        return 1;
    }
    return 0;
}
