/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** null
*/

#include "my.h"
#include "rpg.h"

void get_time(ctime_t *clocker)
{
	clocker->timer = sfClock_getElapsedTime(clocker->clock);
	clocker->seconds = clocker->timer.microseconds / 1000000.0;
}

//	manage_hit_enemy(window); // A MIEUX PLACER
//	manage_notif_right(window, "Tu est pd");
//	manage_notif_left(window, "Tu est pd");
int manage(window_t *window, game_t *game)
{
	if (manage_buttons(window, game) != 0) {
		my_printf("WARNING: ERROR IN BUTTONS !\n");
		return (84);
	}
	if (manage_life(game) != 0
	|| change_area_hud(game) != 0
	|| anim_player(game) != 0
	|| manage_hud_opacity(game) != 0)
		return (84);
	smooth_move_player(game);
	return (0);
}

int game_lobby(window_t *window, game_t *game)
{
	analyse_events(window, game);
	MOUSE_POS = sfMouse_getPosition((const sfWindow *)window->window);
	if (display_scenes(window, game) != 0) {
		my_printf("WARNING: ERROR IN DISPLAY !\n");
		return (84);
	}
	if (manage(window, game) != 0)
		return (84);
	return (0);
}
