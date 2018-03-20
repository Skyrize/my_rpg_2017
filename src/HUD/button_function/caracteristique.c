/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int caracteristique(my_w_t *window)
{
	add_scene_to_display_list(hm_get_bucket(window->scenes, CARAC_GAME),
	window);
	return (0);
}