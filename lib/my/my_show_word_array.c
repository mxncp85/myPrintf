/*
** EPITECH PROJECT, 2022
** CPOOLDAY08
** File description:
** Write a function that displays the content of an array of words.
*/

int my_putstr(char const *str);

void my_putchar(char c);

int my_show_word_array(char * const *tab)
{
    int i = 0;
    while (tab[i] != 0) {
        my_putstr(&tab[i][0]);
        my_putchar('\n');
        i++;
    }
    return 0;
}
