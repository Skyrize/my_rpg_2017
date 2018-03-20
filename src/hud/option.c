/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int option(my_w_t *window)
{
	window->current = hm_get_bucket(window->scenes, OPTION_GAME);
	clean_displayed_scenes_and_add_back(window, OPTION_GAME);
	return (0);
}