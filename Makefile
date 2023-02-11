##
## EPITECH PROJECT, 2022
## B-CPE-101-NAN-1-1-finalstumper-dragos.suceveanu
## File description:
## Makefile
##

TESTS	=	src/my_e_flag.c	\
			src/display_params.c	\
			src/conversion_spec_manager.c	\
			src/my_putfuncs.c	\
			src/my_printf.c	\
			src/put_S_flag.c	\
			src/my_p_flag.c	\
			src/my_f_flag.c	\
			src/my_putbase.c	\
			src/text_manager.c	\
			src/get_params.c	\
			src/my_put_float.c	\
			src/utility_funcs.c

SRC	=	lib/my/comparisons.c			\
			lib/my/display.c				\
			lib/my/my_char_isalpha.c		\
			lib/my/my_compute_power_rec.c	\
			lib/my/my_find_prime_sup.c		\
			lib/my/my_getnbr.c				\
			lib/my/my_is_prime_it.c			\
			lib/my/my_is_prime.c			\
			lib/my/my_isneg.c				\
			lib/my/my_pow.c				\
			lib/my/my_put_nbr.c			\
			lib/my/my_putchar.c			\
			lib/my/my_putstr.c				\
			lib/my/my_revstr.c				\
			lib/my/my_show_word_array.c		\
			lib/my/my_showmem.c				\
			lib/my/my_showstr.c				\
			lib/my/my_sort_int_array.c		\
			lib/my/my_str_isalpha.c			\
			lib/my/my_str_islower.c			\
			lib/my/my_str_isnum.c			\
			lib/my/my_str_isprintable.c		\
			lib/my/my_str_isupper.c			\
			lib/my/my_str_to_word_array.c	\
			lib/my/my_strcapitalize.c		\
			lib/my/my_strcat.c				\
			lib/my/my_strcmp.c				\
			lib/my/my_strcpy.c				\
			lib/my/my_strdup.c				\
			lib/my/my_strlen.c				\
			lib/my/my_strlowcase.c			\
			lib/my/my_strncat.c				\
			lib/my/my_strncmp.c				\
			lib/my/my_strncpy.c				\
			lib/my/my_strstr.c				\
			lib/my/my_strupcase.c			\
			lib/my/my_swap.c				\
			lib/my/rev_char.c				\
			lib/my/word_size.c 				\
			src/my_printf.c					\
			src/conversion_spec_manager.c	\
			src/display_params.c			\
			src/my_putfuncs.c				\
			src/my_e_flag.c					\
			src/put_S_flag.c				\
			src/my_p_flag.c 				\
			src/my_putbase.c				\
			src/text_manager.c				\
			src/get_params.c				\
			src/my_put_float.c				\
			src/my_f_flag.c 				\
			src/my_g_flag.c 				\
			src/utility_funcs.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

TESTFLAGS	=	-lcriterion --coverage

LIB	=	-L . -lmy

INCLUDE = -I include/

TESTS_PATH = tests/test_my_printf.c

TEST_FLAGS = --coverage -lcriterion

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

test:
	gcc -o unit_tests $(TESTS) $(INCLUDE) $(LIB) $(TESTS_PATH) $(TEST_FLAGS)
	./unit_tests && gcovr && gcovr --exclude tests/ --branches

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests

re:	fclean all
