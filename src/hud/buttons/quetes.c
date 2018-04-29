/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int quetes(window_t *window, game_t *game)
{
	static char *old_scene = NULL;
	
	if (!window || !game)
		return (84);
	if (my_strcmp(CURRENT_SCENE->key, "QUESTS"))
		old_scene = CURRENT_SCENE->key;
	return (button_display_hide_scene(QUESTS_GAME, NULL, game, old_scene));
}
