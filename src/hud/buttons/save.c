/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int save(my_w_t *window)
{
	int error_no = 0;

	clean_displayed_scene_name(window, PAUSE_GAME);
	error_no = add_scene_to_display_list(
	hm_get_bucket(SCENES, SAVE_GAME), window);
	if (error_no == 84)
		return (84);
	return (1);
}

int yes_save(my_w_t *window)
{
	int error_no = 0;

	clean_displayed_scene_name(window, SAVE_GAME);
	error_no = add_scene_to_display_list(
	hm_get_bucket(SCENES, PAUSE_GAME), window);
	if (error_no == 84)
		return (84);
	return (1);
}

int no_save(my_w_t *window)
{
	int error_no = 0;

	clean_displayed_scene_name(window, SAVE_GAME);
	error_no = add_scene_to_display_list(
	hm_get_bucket(SCENES, PAUSE_GAME), window);
	if (error_no == 84)
		return (84);
	return (1);
}