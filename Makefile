##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## .
##

SRC	=	src/main.c \
		src/linked_list.c	\
		src/my_str_to_word_array.c	\
		src/fridgeloop.c	\
		src/exit_fridge.c	\
		src/display_command.c	\
		src/fridgeloop_utils.c	\
		src/make_command.c	\
		src/buffer_utils.c	\
		src/free_utils.c

OBJ	=	$(SRC:.c=.o)

NAME	=	fridge

INC	=	-I include/

LMY	=	-L lib/my/ -lmy

all:	$(NAME) $(OBJ)

$(NAME):	$(OBJ)
	make -C ./lib/my/
	gcc $(SRC) -o $(NAME) $(LMY) $(INC) -g3 -Wall -Wextra -W

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(OBJ)
	rm -f $(NAME)

re:	fclean all