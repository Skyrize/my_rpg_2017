/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "rpg.h"

int menu_principale(my_w_t *window)
{
	window->current = hm_get_bucket(window->scenes, HOME);
	clean_displayed_scenes_and_add_back(window, HOME);
	return (0);
}