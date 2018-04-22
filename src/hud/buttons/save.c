/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int save(window_t *window, game_t *game)
{
	int my_errno = 0;

	clean_displayed_scene_name(game, PAUSE_GAME);
	my_errno = add_scene_to_display_list(
	hm_get_bucket(SCENES, SAVE_GAME), game);
	if (my_errno == 84)
		return (84);
	(void)window;
	return (1);
}

int yes_save(window_t *window, game_t *game)
{
	int my_errno = 0;

	clean_displayed_scene_name(game, SAVE_GAME);
	my_errno = add_scene_to_display_list(
	hm_get_bucket(SCENES, PAUSE_GAME), game);
	if (my_errno == 84)
		return (84);
	(void)window;
	return (1);
}

int no_save(window_t *window, game_t *game)
{
	int my_errno = 0;

	clean_displayed_scene_name(game, SAVE_GAME);
	my_errno = add_scene_to_display_list(
	hm_get_bucket(SCENES, PAUSE_GAME), game);
	if (my_errno == 84)
		return (84);
	(void)window;
	return (1);
}