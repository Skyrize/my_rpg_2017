/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int reload(window_t *window)
{
	int error_no = 0;

	CURRENT_SCENE = hm_get_bucket(SCENES, LOAD_GAME);
	error_no = clean_displayed_scenes_and_add_back(window, LOAD_GAME);
	if (error_no == 84)
		return (84);
	return (1);
}
