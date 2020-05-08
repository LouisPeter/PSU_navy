##
## EPITECH PROJECT, 2018
## Makefile of marius
## File description:
## makefile
##

SRC = 	feature1.c						\
		feature2.c						\
		get_next_line.c					\
		my_getnbr.c						\
		my_isneg.c						\
		my_printf.c						\
		my_printf2.c					\
		my_putchar.c					\
		my_put_nbr.c					\
		my_putstr.c						\
		my_revstr.c						\
		my_strcat.c						\
		my_strcpy.c						\
		my_strdup.c						\
		my_strlen.c						\
		my_strncpy.c					\
		my_str_to_word_array.c			\
		my_swap.c						\
		features_navy.c					\
		my_cat.c						\
		my_clear_str.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all	=	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME)	$(OBJ)
	cp $(NAME) ../

clean:
	rm -f $(OBJ)
	rm -f ../$(NAME)

fclean:	clean
	rm -f $(NAME)
