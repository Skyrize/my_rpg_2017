/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int pause_game(my_w_t *window)
{
	window->current = hm_get_bucket(window->scenes, PAUSE_GAME);
	clean_displayed_scenes_and_add_back(window, PAUSE_GAME);
	return (0);
}