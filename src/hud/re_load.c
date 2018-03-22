/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int re_load(my_w_t *window)
{
	int error_no = 0;

	window->current = hm_get_bucket(window->scenes, RE_LOAD);
	error_no = clean_displayed_scenes_and_add_back(window, RE_LOAD);
	if (error_no == 84)
		return (84);
	return (1);
}
