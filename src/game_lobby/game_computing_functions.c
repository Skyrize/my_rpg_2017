/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** null
*/

#include "my.h"
#include "rpg.h"

void get_time(my_w_t *window)
{
	window->clocker.timer = sfClock_getElapsedTime(window->clocker.clock);
	window->clocker.seconds =
	window->clocker.timer.microseconds / 1000000.0;
}

void compute_game(my_w_t *window)
{
	(void)window;
}

int game_lobby(my_w_t *window, bucket_t *current_scene)
{
	analyse_events(window);
	compute_game(window);
	if (display_scene(window, current_scene) != 0)
		return (84);
	display_scene(window, hm_get_bucket(window->scenes, "TEST"));
	return (0);
}
