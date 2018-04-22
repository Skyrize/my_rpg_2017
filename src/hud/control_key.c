/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int control_key(my_w_t *window)
{
	int error_no = 0;

	if (!window || !window->current || !window->scenes)
		return (84);
	window->current = hm_get_bucket(window->scenes, CONTROL_KEY);
	error_no = clean_displayed_scenes_and_add_back(window, CONTROL_KEY);
	if (error_no == 84)
		return (84);
	return (1);
}
