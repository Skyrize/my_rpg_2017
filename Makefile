##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## all clean fclean re
##

SRC	=	main.c	\
		src/init/my_initializer.c	\
		src/init/file_analysing.c	\
		src/init/init_from_file_readed.c	\
		src/init/scenes_tab_init.c	\
		src/init/list_filling_init.c	\
		src/init/init_libs.c	\
		src/init/init_words.c	\
		src/init/init_words_2.c	\
		src/input/input_functions.c	\
		src/warning_functions/init_warning.c	\
		src/warning_functions/init_warning_2.c	\
		src/warning_functions/display_warning.c	\
		src/list_management/objs_list_creation.c	\
		src/game_lobby/game_computing_functions.c	\
		src/game_display/display_lobby.c	\
		src/game_display/display_objs.c	\
		src/game_display/display_texts.c	\
		src/free_destroy/free_and_destroy_lobby.c	\

OBJS	=	$(SRC:.c=.o)

NAME_BINARY	=	my_rpg

NAME	=	my_rpg

NAME2	=	unit-tests

LFLAGS	=	-lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window
#-lc_graph_prog

CFLAGS	=	 -Wall -Wextra -W -g3 -I./include/ -L./lib/my -lmy

CC	=	gcc

all:	prepare_lib $(NAME)

prepare_lib:
	make -C lib/my

tests_run:	prepare_lib
	make -C tests/
	tests/unit-tests


$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LFLAGS) $(CFLAGS)

clean:
	make clean -C lib/my
	make clean -C tests/
	$(RM) $(OBJS)

fclean:	clean
	make fclean -C tests/
	make fclean -C lib/my/
	$(RM) $(NAME)

re:	fclean all
re_game: fclean game
