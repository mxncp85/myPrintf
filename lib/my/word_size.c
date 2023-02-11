/*
** EPITECH PROJECT, 2022
** CPOOLDAY08
** File description:
** Write a function that displays the content of an array of words.
*/

int my_char_isalpha(char *a);

int word_size(char const *str)
{
    int wl = 0;
    int i = 0;
    while (my_char_isalpha(str[i]) == 1) {
        wl++;
        i++;
    }
    return wl;
}
