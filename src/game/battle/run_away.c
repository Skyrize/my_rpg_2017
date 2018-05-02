/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** run_away
*/

#include "rpg.h"

int run_away(window_t *window, game_t *game)
{
	int run = rand() % 100;

	if (!window || !game)
		return (84);
	if (run >= 85)
		display_special_hit_player(window, game, "RUN_SUCCESS");
	else
		display_special_hit_player(window, game, "RUN_FAIL");
	return (0);
}