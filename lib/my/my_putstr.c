/*
** EPITECH PROJECT, 2022
** CPOOLDAY04
** File description:
** Displays one by one the characters of a string
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0' ; i++) {
        my_putchar(str[i]);
    }
}
