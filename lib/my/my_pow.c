/*
** EPITECH PROJECT, 2022
** CPOOLDAY03
** File description:
** Displays N if integer is negative, displays P if null or positive
*/

int my_pow(int nb, char power)
{
    while (power - 1 >= 0) {
        nb = nb * 10;
        power--;
    }
    return nb;
}
