/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "rpg.h"

int menu_principale(my_w_t *window)
{
	int error_no = 0;

	window->current = hm_get_bucket(window->scenes, HOME);
	error_no = clean_displayed_scenes_and_add_back(window, HOME);
	if (error_no == 84)
		return (84);
	return (1);
	return (0);
}
