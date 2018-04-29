/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_battle
*/

#include "rpg.h"

int battle_events(game_t *game)
{
	update_element_in_battle(game);
	return (0);
}

int battle_lobby(window_t *window, game_t *game)
{
	(void)window;
	display_characters(window, game);
	if (battle_events(game) != 0)
		return (84);
	return (0);
}