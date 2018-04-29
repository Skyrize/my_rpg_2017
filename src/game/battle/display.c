/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** display
*/

#include "rpg.h"

int display_characters(window_t *window, game_t *game)
{
	sfRenderWindow_drawRectangleShape(window->window,
	PLAYER_CHARACTER->obj, NULL);
	if (game->enemy[0].rec)
		sfRenderWindow_drawRectangleShape(window->window,
		game->enemy[0].rec, NULL);
	if (game->enemy[1].rec)
		sfRenderWindow_drawRectangleShape(window->window,
		game->enemy[1].rec, NULL);
	if (game->enemy[2].rec)
		sfRenderWindow_drawRectangleShape(window->window,
		game->enemy[2].rec, NULL);
	return (0);
}