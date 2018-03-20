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
		src/init/init_map.c	\
		src/init/scene_keys_functions_01.c	\
		src/init/scene_keys_functions_02.c	\
		src/init/texture_keys_functions_01.c	\
		src/init/texture_keys_functions_02.c	\
		src/init/map_keys_functions.c	\
		src/init/zone_keys_functions.c	\
		src/init/audio_and_fonts_keys_functions.c	\
		src/input/input_functions.c	\
		src/warnings/init_warning_unexisting.c	\
		src/warnings/init_warning_invalid.c	\
		src/warnings/init_warning_invalid_02.c	\
		src/warnings/init_warning_already_existing_01.c	\
		src/warnings/init_warning_already_existing_02.c	\
		src/warnings/init_warning_already_existing_03.c	\
		src/warnings/init_warning_missing.c	\
		src/warnings/init_warning_undefined.c	\
		src/warnings/ingame_warning.c	\
		src/list_management/objs_list_create.c	\
		src/list_management/objs_list_add.c	\
		src/list_management/objs_list_remove.c	\
		src/game_lobby/game_computing_functions.c	\
		src/game_display/display_lobby.c	\
		src/game_display/display_map.c	\
		src/game_display/display_objs.c	\
		src/game_display/display_texts.c	\
		src/game_display/move_rect.c	\
		src/free_destroy/free_and_destroy_lobby.c	\
		src/HUD/button_function/caracteristique.c \
		src/HUD/button_function/credits.c \
		src/HUD/button_function/exit.c \
		src/HUD/button_function/inventaire.c \
		src/HUD/button_function/load.c \
		src/HUD/button_function/map.c \
		src/HUD/button_function/new_game.c \
		src/HUD/button_function/option.c \
		src/HUD/button_function/pause.c \
		src/HUD/button_function/quetes.c \
		src/HUD/button_function/quit.c \
		src/HUD/button_function/re_load.c \
		src/HUD/button_function/resume.c \
		src/HUD/button_function/save.c \
		src/HUD/init_func_button.c \

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
