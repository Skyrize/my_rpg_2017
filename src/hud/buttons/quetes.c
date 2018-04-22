/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int quetes(window_t *window, game_t *game)
{
	(void)window;
	return (button_display_hide_scene(QUESTS_GAME,
		NULL, game));
}
