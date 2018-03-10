/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_invalid_texture(sfTexture *texture, char *texture_name)
{
	if (!texture) {
		my_printf("WARNING: CAN'T FIND TEXTURE '%s' IN TEXTURE LIB !\n",
		texture_name);
		return (84);
	}
	return (0);
}

int check_unexisting_font(sfFont *font, char *font_name)
{
	if (!font) {
		my_printf("WARNING: CAN'T FIND FONT '%s' IN FONT LIB !\n",
		font_name);
		return (84);
	}
	return (0);
}

int check_missing_information_for_obj(char **infos)
{
	if (!infos || !infos[0] || !infos[1] || !infos[2]) {
		my_printf("WARNING: MISSING DATA FOR OBJ INIT !\n");
		return (84);
	}
	return (0);
}

int check_missing_information_for_text(char **infos)
{
	if (!infos || !infos[0] || !infos[1] || !infos[2] || !infos[3] || !infos[4]) {
		my_printf("WARNING: MISSING DATA FOR TEXT INIT !\n");
		return (84);
	}
	return (0);
}

int check_invalid_obj_init(char **obj_type, char **obj_x, char **obj_y)
{
	if (WRONG_OBJ_INIT) {
		my_printf("WARNING: INVALID OBJ INIT\n");
		return (84);
	}
	return (0);
}
