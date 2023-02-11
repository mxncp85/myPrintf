/*
** EPITECH PROJECT, 2022
** CPOOLDAY05
** File description:
** Calculates the power of a number (recursive way)
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    }
    if (p != 1) {
        return nb * my_compute_power_rec(nb, p - 1);
    } else {
        return nb;
    }
}
