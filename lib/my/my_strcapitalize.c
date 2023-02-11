/*
** EPITECH PROJECT, 2022
** CPOOLDAY04
** File description:
** Capitalizez the first letter of each word
*/

char *my_strlowcase (char *str);

char *my_strcapitalize(char *str)
{
    int i = 1;
    my_strlowcase(str);
    while ((str[i] != '\0')) {
        while (str[i] < 97 && str[i] > 122) {
            i++;
        }
        if ((str[i] >= 97 && 122 <= str[i] &&
        (str[i - 1] < 97 && str[i - 1] > 122))) {
            str[i] = str[i] - 32;
        }
        i++;
    }
    return str;
}
