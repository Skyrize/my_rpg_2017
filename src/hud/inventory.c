/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int inventory(my_w_t *window)
{
	int error_no = 0;

	error_no = add_scene_to_display_list(
	hm_get_bucket(window->scenes, INVENTORY_GAME), window);
	if (error_no == 84)
		return (84);
	return (1);
}
