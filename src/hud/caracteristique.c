/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int characteristique(my_w_t *window)
{
	return (button_display_hide_scene(CHARAC_GAME,
		&update_characteristics, window));
}
