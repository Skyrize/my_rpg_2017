/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_unexisting_texture(sfTexture *texture, char *texture_name)
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

int check_unexisting_music(sfMusic *music, char *music_name)
{
	if (!music) {
		my_printf("WARNING: CAN'T FIND MUSIC '%s' AT INITIALISATION!\n",
		music_name);
		return (84);
	}
	return (0);
}
