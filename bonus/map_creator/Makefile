##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## all clean fclean re
##

SRC	=	src/init/file_analysing.c	\
		src/init/init_from_file_readed.c	\
		src/init/list_filling_init.c	\
		src/init/init_libs.c	\
		src/init/init_map.c	\
		src/init/texture_keys_functions_01.c	\
		src/init/texture_keys_functions_02.c	\
		src/init/map_keys_functions.c	\
		src/init/zone_keys_functions.c	\
		src/warnings/init_warning_unexisting.c	\
		src/warnings/init_warning_invalid.c	\
		src/warnings/init_warning_invalid_02.c	\
		src/warnings/init_warning_already_existing_01.c	\
		src/warnings/init_warning_already_existing_02.c	\
		src/warnings/init_warning_already_existing_03.c	\
		src/warnings/init_warning_missing.c	\
		src/warnings/init_warning_undefined.c	\
		src/map_creator/absolute_value.c	\
		src/map_creator/compute_near_point.c	\
		src/map_creator/compute_near_tile.c	\
		src/map_creator/draw_gui.c	\
		src/map_creator/draw_nearest_thing.c	\
		src/map_creator/edit_map.c	\
		src/map_creator/events.c	\
		src/map_creator/main.c	\
		src/map_creator/ressources.c	\
		src/map_creator/structures.c	\
		src/map_creator/window.c	\
		src/map_creator/menu/init_menu.c	\
		src/map_creator/menu/menu_events.c	\
		src/map_creator/menu/menu_loop.c	\
		src/map_creator/render/camera.c	\
		src/map_creator/render/map.c	\
		src/map_creator/render/painter.c	\
		src/map_creator/render/render.c	\
		src/list_management/objs_list_create.c	\
		src/list_management/objs_list_add.c	\
		src/list_management/objs_list_remove.c	\
		src/free_destroy/free_and_destroy_lobby.c	\

OBJS	=	$(SRC:.c=.o)

NAME	=	my_map_editor

LFLAGS	=	-lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window
#-lc_graph_prog

CFLAGS	=	 -Wall -Wextra -W -g3 -I./../../include/ -L./../../lib/my -lmy -lm

CC	=	gcc

all:	prepare_lib $(NAME)

prepare_lib:
	make -C ../../lib/my

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LFLAGS)

clean:
	make clean -C ../../lib/my
	$(RM) $(OBJS)

fclean:	clean
	make fclean -C ../../lib/my/
	$(RM) $(NAME)

re:	fclean all
