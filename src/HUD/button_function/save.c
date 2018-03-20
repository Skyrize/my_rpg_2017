/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int save(my_w_t *window)
{
	window->current = hm_get_bucket(window->scenes, SAVE_GAME);
	clean_displayed_scenes_and_add_back(window, SAVE_GAME);
	return (0);
}