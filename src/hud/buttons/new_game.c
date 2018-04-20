/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int new_game(window_t *window)
{
	CURRENT_SCENE = hm_get_bucket(SCENES, "NEW_GAME");
	if (clean_displayed_scenes_and_add_back(window, "NEW_GAME") != 0)
		return (84);
	return (1);
}
