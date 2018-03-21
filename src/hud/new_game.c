/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int new_game(my_w_t *window)
{
	window->current = hm_get_bucket(window->scenes, "GAME");
	clean_displayed_scenes_and_add_back(window, "GAME");
	return (0);
}