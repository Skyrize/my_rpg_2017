/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** lobby.c
*/

#include "rpg.h"

int inventory_lobby(window_t *window, game_t *game)
{
	analyse_events(window, game);
	//display_inventory();
	if (manage_inventory_buttons(game) != 0)
		return (84);
	return (0);
}