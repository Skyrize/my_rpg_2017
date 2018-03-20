/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int re_load(my_w_t *window)
{
	window->current = hm_get_bucket(window->scenes, RE_LOAD);
	clean_displayed_scenes_and_add_back(window, RE_LOAD);
	return (0);
}