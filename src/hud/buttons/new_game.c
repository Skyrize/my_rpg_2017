/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int new_game(window_t *window, game_t *game)
{
	(void)window;
	CURRENT_SCENE = hm_get_bucket(SCENES, "NEW_GAME");
	if (clean_displayed_scenes_and_add_back(game, "NEW_GAME") != 0)
		return (84);
	return (1);
}
