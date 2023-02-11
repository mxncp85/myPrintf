/*
** EPITECH PROJECT, 2022
** CPOOLDAY05
** File description:
** Finds out if a number is prime or not
*/

int my_pow(int nb, char power);

void my_putchar(char c);

void display(long nb, char dg_count)
{
    char digit;

    while (dg_count > 0) {
        dg_count--;
        digit = nb / my_pow(10, dg_count - '0');
        nb = nb - my_pow(10, dg_count) * digit;
        digit = digit + 48;
        my_putchar(digit);
    }
    digit = nb % 10;
    digit = digit + 48;
    if (nb != 0) {
        my_putchar(digit);
    }
    if ((nb % 10 == 0) && (nb != 0)) {
        my_putchar(48);
    }
}
