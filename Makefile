##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## .
##

SRC	=	src/main.c \
		src/linked_list.c

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