/*
** EPITECH PROJECT, 2022
** CPOOLDAY05
** File description:
** Finds out if a number is prime or not
*/

int my_is_prime(int nb)
{
    static int i = 1;
    static int res = 0;

    if (nb >= i) {
        if (nb % i == 0) {
            res++;
        }
        i++;
        my_is_prime (nb);
    } else {
        return 0;
    }
    if ((res > 2) || (nb == 1)) {
        return 0;
    }
    return 1;
}
