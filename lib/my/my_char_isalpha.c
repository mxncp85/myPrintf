/*
** EPITECH PROJECT, 2022
** CPOOLDAY05
** File description:
** Write a function that returns the smallest prime number that is greater than,
** or equal to, the number given as a parameter.
*/

int my_char_isalpha(char *a)
{
    if (a >= 48 && a <= 57) {
        return 1;
    }
    if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) {
        return 1;
    }
    return 0;
}
