/*
** EPITECH PROJECT, 2022
** CPOOLDAY05
** File description:
** Write a function that returns the smallest prime number that is greater than,
** or equal to, the number given as a parameter.
*/

int comparisons(int len1, int len2, int diff)
{
    if (len1 > len2) {
        return 1;
    }
    if (len1 < len2) {
        return -1;
    }
    if (diff > 0) {
        return 1;
    }
    if (diff < 0) {
        return -1;
    }
    if (diff == 0) {
        return 0;
    }
}
