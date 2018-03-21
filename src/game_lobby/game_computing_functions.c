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

int game_lobby(my_w_t *window)
{
	analyse_events(window);
	MOUSE_POS = sfMouse_getPosition((const sfWindow *)
	window->window);
	compute_game(window);
	if (manage_buttons(window) == 1)
		return (1);
	if (display_scenes(window) != 0)
		return (84);
	return (0);
}
