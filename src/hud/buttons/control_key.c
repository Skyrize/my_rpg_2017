/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int control_key(window_t *window)
{
	int error_no = 0;

	CURRENT_SCENE = hm_get_bucket(SCENES, CONTROL_KEY);
	error_no = clean_displayed_scenes_and_add_back(window, CONTROL_KEY);
	if (error_no == 84)
		return (84);
	return (1);
}
