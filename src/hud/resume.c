/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int game(my_w_t *window)
{
	window->current = hm_get_bucket(window->scenes, "GAME");
	if (clean_displayed_scenes_and_add_back(window, "GAME") != 0)
		return (84);
	if (add_scene_to_display_list(
		hm_get_bucket(window->scenes, "HEALTH_HUD"), window) != 0)
		return (84);
	return (1);
}

int resume(my_w_t *window)
{
	window->current = hm_get_bucket(window->scenes, "GAME");
	clean_displayed_scene_name(window, PAUSE_GAME);
	return (1);
}
