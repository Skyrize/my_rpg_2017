/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int quit(window_t *window)
{
	CURRENT_SCENE = hm_get_bucket(SCENES, QUIT_GAME);
	if (clean_displayed_scenes_and_add_back(window, QUIT_GAME) != 0)
		return (84);
	return (1);
}
