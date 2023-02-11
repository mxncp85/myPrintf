/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday09-dragos.suceveanu
** File description:
** my header
*/

#ifndef MY_H_
    #define MY_H_
    int my_compute_power_rec(int, int);
    int my_compute_square_root(int);
    int my_find_prime_sup(int);
    int my_is_prime_it(int);
    int my_getnbr(char const *);
    int my_is_prime(int);
    int my_isneg(int);
    int my_put_nbr(int);
    void display(int, char);
    int my_pow(int, int);
    void my_putchar(char);
    int my_putstr(char const *);
    char *my_revstr(char*);
    char rev_char(char, char);
    int my_showmem(char const *, int);
    int my_showstr(char const *);
    void my_sort_int_array(int *, int);
    int my_str_isalpha(char const *);
    int my_str_islower(char const *);
    int my_str_isnum(char const *);
    int my_str_isprintable(char const *);
    int my_str_isupper(char const *);
    char *my_strcapitalize(char *);
    char *my_strcat(char * , char const *);
    int my_strcmp(char const *, char const *);
    int comparison(int, int, int);
    char *my_strcpy(char *, char const *);
    int my_strlen(char const *);
    char *my_strlowcase(char *);
    char *my_strncat(char *, char const *, int);
    int my_strncmp(char const   *, char const *, int);
    char *my_strncpy(char *, char const *, int);
    char *my_strstr(char *, char const *);
    char *my_strupcase(char *);
    void my_swap(int *,int *);
    int word_size(char const *);
    char *my_strdup(char const *);
    int my_char_isalpha(char *);
    int my_show_word_array(char * const *tab);
    char **my_str_to_word_array(char const *str);
#endif /* !MY_H_ */
