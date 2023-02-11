/*
** EPITECH PROJECT, 2022
** CPOOLDAY05
** File description:
** Finds out the square root of a number
** if the result is not a whole number, returns 0 (recursive way)
*/

int my_compute_square_root(int nb)
{
    int i = 2;
    int res;

    if (check_root(nb) == 0) {
        return 0;
    }
    while (nb % i != 0) {
        i++;
    }
    nb = nb / i;
    if (nb / i != 1 ) {
        res = i * my_compute_square_root(nb / i);
        return res;
    } else {
        return i;
    }
}
