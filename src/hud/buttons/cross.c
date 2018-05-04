/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int cross(window_t *window, game_t *game)
{
	if (!window || !game)
		return (84);
	clean_displayed_scene_name(game, "BATTLE_END_SCREEN");
	return (0);
}
