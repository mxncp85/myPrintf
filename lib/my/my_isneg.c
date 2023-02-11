/*
** EPITECH PROJECT, 2022
** CPOOLDAY03
** File description:
** Displays N if integer is negative, displays P if null or positive
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar(78);
    } else {
        my_putchar(80);
    }
    return 0;
}
