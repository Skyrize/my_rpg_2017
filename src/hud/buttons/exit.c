/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int exit_game(window_t *window, game_t *game)
{
	(void)game;
	sfRenderWindow_close(window->window);
	return (0);
}
