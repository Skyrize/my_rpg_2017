/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int quit(my_w_t *window)
{
	window->current = hm_get_bucket(window->scenes, QUIT_GAME);
	clean_displayed_scenes_and_add_back(window, QUIT_GAME);
	return (0);
}