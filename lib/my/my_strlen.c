/*
** EPITECH PROJECT, 2022
** CPOOLDAY04
** File description:
** Finds out length of a string
*/

int my_strlen(char const *str)
{
    int cnt = 0;
    for (int i = 0 ; str[i] != '\0' ; i++) {
        cnt++;
    }
    return cnt;
}
