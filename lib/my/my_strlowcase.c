/*
** EPITECH PROJECT, 2022
** CPOOLDAY06
** File description:
** Turns string into lowercase
*/

char *my_strlowcase (char *str)
{
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if ((str[i] >= 65) && (90 <= str[i])) {
            str[i] = str[i] + 32;
        }
    }
    return str;
}
