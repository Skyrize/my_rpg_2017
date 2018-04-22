/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int stats(window_t *window, game_t *game)
{
	(void)window;
	return (button_display_hide_scene(STATS_GAME,
		&update_stats, game));
}
