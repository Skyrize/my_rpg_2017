/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int inventory(my_w_t *window)
{
	window->current = hm_get_bucket(window->scenes, INVENTORY_GAME);
	clean_displayed_scenes_and_add_back(window, INVENTORY_GAME);
	return (0);
}