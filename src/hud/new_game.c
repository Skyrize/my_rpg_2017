/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int new_game(my_w_t *window)
{
	int error_no = 0;

	window->current = hm_get_bucket(window->scenes, "NEW_GAME");
	error_no = clean_displayed_scenes_and_add_back(window, "NEW_GAME");
	if (error_no == 84)
		return (84);
	return (1);
}
