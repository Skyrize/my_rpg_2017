/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int load(my_w_t *window)
{
	window->current = hm_get_bucket(window->scenes, LOAD_GAME);
	clean_displayed_scenes_and_add_back(window, LOAD_GAME);
	return (0);
}