/*
** EPITECH PROJECT, 2022
** CPOOLDAY05
** File description:
** Write a function that returns the smallest prime number that is greater than,
** or equal to, the number given as a parameter.
*/

int my_is_prime_it(int nb);

int my_find_prime_sup(int nb)
{
    if (nb % 2 == 0) {
        nb++;
    }
    if (my_is_prime_it(nb) != 1) {
        my_find_prime_sup(nb + 1);
    } else {
        return nb;
    }
}
