/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int end_screen_cross(window_t *window, game_t *game)
{
	if (!window || !game)
		return (84);
	clean_displayed_scene_name(game, "WIN_SCREEN");
	CURRENT_BUCKET = hm_get_bucket(SCENES, "GAME");
	if (game->battle.lose)
		lose_tp(game);
	return (1);
}

int lvl_up_cross(window_t *window, game_t *game)
{
	if (!window || !game)
		return (84);
	clean_displayed_scene_name(game, "LEVEL_UP");
	CURRENT_BUCKET = hm_get_bucket(SCENES, "GAME");
	return (1);
}
