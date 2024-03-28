##
## EPITECH PROJECT, 2022
## the_makefile
## File description:
## makefile_the
##

CC	=	gcc

SRC	=	src/compteur.c	\
		src/my_putchar.c	\
		src/check_win.c	\
		src/my_putstr.c	\
		src/move_player_uplr.c	\
		src/detect_o.c	\
		src/detect_pos_p.c	\
		src/display_map.c	\
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

CPPFLAGS = -I./include/

all:$(NAME)

$(NAME):        $(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses

debug:  CFLAGS += -g3

debug:  all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
