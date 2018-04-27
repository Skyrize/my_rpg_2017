/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int map(window_t *window, game_t *game)
{
	static char *old_scene = NULL;
	
	if (my_strcmp(CURRENT_SCENE->key, "STATS"))
		old_scene = CURRENT_SCENE->key;
	if (!window || !game)
		return (84);
	return (button_display_hide_scene(MAP_GAME, NULL, game, old_scene));
}
