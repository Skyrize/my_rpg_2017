/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** null
*/

#include "my.h"
#include "rpg.h"

void get_time(window_t *window)
{
	window->clocker.timer = sfClock_getElapsedTime(window->clocker.clock);
	window->clocker.seconds =
	window->clocker.timer.microseconds / 1000000.0;
}

int manage(window_t *window)
{
	if (manage_buttons(window) != 0 || manage_life(window) != 0) {
		my_printf("ERROR IN MANAGEMENT\n");
		return (84);
	}
	change_area_hud(window);
	anim_player(window);
	smooth_move_player(window);
	manage_hud_opacity(window);
	return (0);
}

int game_lobby(window_t *window)
{
	analyse_events(window);
	MOUSE_POS = sfMouse_getPosition((const sfWindow *)window->window);
	if (display_scenes(window) != 0) {
		my_printf("WARNING: ERROR IN DISPLAY !\n");
		return (84);
	}
	if (manage(window) == 84)
		return (84);
	return (0);
}
