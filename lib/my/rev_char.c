/*
** EPITECH PROJECT, 2022
** CPOOLDAY06
** File description:
** Reverses the string
*/

char rev_char (char *a, char *b)
{
    char swap;

    swap = *a;
    *a = *b;
    *b = swap;
}
