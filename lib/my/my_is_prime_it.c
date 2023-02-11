/*
** EPITECH PROJECT, 2022
** CPOOLDAY05
** File description:
** Write a function that returns the smallest prime number that is greater than,
** or equal to, the number given as a parameter.
*/

int my_is_prime_it(int nb)
{
    int i = 1;
    int fact_count = 0;
    while (nb >= i) {
        if (nb % i == 0) {
            fact_count++;
        }
        i++;
    }
    if ((fact_count > 2) || (nb <= 1)){
        return 0;
    }
    return 1;
}
