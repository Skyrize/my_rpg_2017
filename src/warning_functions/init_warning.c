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
	if (!infos || !infos[0] || !infos[1] || !infos[2] || !infos[3]) {
		my_printf("WARNING: MISSING DATA FOR OBJ INIT !\n");
		return (84);
	}
	return (0);
}

int check_missing_information_for_text(char **infos)
{
	if (!infos || !infos[0] || !infos[1] || !infos[2] || !infos[3]
		|| !infos[4]|| !infos[5]) {
		my_printf("WARNING: MISSING DATA FOR TEXT INIT !\n");
		return (84);
	}
	return (0);
}

int check_invalid_obj_init(obj_infos_t *obj)
{
	if (!obj->name || !obj->type || !obj->x || !obj->y
		|| !obj->name[0] || !obj->name[1]
		|| !obj->type[0] || !obj->type[1]
		|| !obj->x[0] || !obj->x[1]
		 || !obj->y[0] || !obj->y[1]
		|| my_fastcmp(obj->name[0], OBJ_KEYWORD) == 1
		|| my_fastcmp(obj->type[0], TEXTURE_KEYWORD) == 1
		|| my_fastcmp(obj->x[0], X_KEYWORD) == 1
		|| my_fastcmp(obj->y[0], Y_KEYWORD) == 1) {
		my_printf("WARNING: INVALID OBJ INIT\n");
		return (84);
	}
	return (0);
}
