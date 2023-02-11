/*
** EPITECH PROJECT, 2022
** CPOOLDAY06
** File description:
** Reverses the string
*/

char *my_strupcase (char *str)
{
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if ((str[i] >= 97) && (122 <= str[i])) {
            str[i] = str[i] - 32;
        }
    }
    return str;
}
