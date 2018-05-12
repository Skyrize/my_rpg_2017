/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** quest_1
*/

#include "rpg.h"

int quest_1(window_t *window, game_t *game)
{
	if (!window || !game)
		return (84);
	make_sound("NEW_QUEST", game);
	// add quest_to_player
	return (0);
}