/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int quetes(my_w_t *window)
{
	int error_no = 0;

	window->current = hm_get_bucket(window->scenes, QUETES_GAME);
	error_no = clean_displayed_scenes_and_add_back(window, QUETES_GAME);
	if (error_no == 84)
		return (84);
	return (1);
}
