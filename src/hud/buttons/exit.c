/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int exit_game(window_t *window)
{
	sfRenderWindow_close(window->window);
	return (0);
}
