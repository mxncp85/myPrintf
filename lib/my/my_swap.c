/*
** EPITECH PROJECT, 2022
** TestCPOOL04
** File description:
** Swap
*/

void my_swap(int *a, int *b)
{
    int swap;

    swap = *a;
    *a = *b;
    *b = swap;
}
