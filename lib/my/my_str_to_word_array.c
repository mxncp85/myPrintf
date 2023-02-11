/*
** EPITECH PROJECT, 2022
** CPOOLDAY08
** File description:
** Write a function that displays the content of an array of words.
*/

#include <stdlib.h>

int my_strlen(char const *str);

int my_char_isalpha(char *a);

int word_size(char const *str);

char **my_str_to_word_array(char const *str)
{
    char **word_array = malloc(my_strlen(str) * sizeof(char*));
    int a = 0;
    int b = 0;
    int i = 0;
    for (i ; str[i] != '\0' && i <= my_strlen(str) ; i++) {
        if (my_char_isalpha(str[i]) == 1) {
            word_array[a] = malloc(sizeof(char) * word_size(&str[i]));
        }
        while (my_char_isalpha(str[i]) == 1) {
            word_array[a][b] = str[i];
            i++;
            b++;
        }
        if (my_char_isalpha(str[i - b]) == 1) {
            word_array[a][b + 1] = '\0';
            a++;
        }
        b = 0;
    }
    return word_array;
}
