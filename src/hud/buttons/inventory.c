/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int inventory(window_t *window, game_t *game)
{
	static char *old_scene = NULL;
	
	if (!window || !game)
		return (84);
	if (my_strcmp(CURRENT_BUCKET->key, "INVENTORY"))
		old_scene = CURRENT_BUCKET->key;
	return (button_display_hide_scene(INVENTORY_GAME,
		NULL, game, old_scene));
}
