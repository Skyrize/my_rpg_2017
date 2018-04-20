/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int option(window_t *window)
{
	int error_no = 0;

	CURRENT_SCENE = hm_get_bucket(SCENES, OPTION_GAME);
	error_no = clean_displayed_scenes_and_add_back(window, OPTION_GAME);
	if (error_no == 84)
		return (84);
	return (1);
}
