/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int stats(my_w_t *window)
{
	return (button_display_hide_scene(STATS_GAME,
		&update_stats, window));
}
