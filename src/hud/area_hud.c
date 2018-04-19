/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** area_hud
*/

#include "rpg.h"

int change_area_hud(my_w_t *window)
{
	scene_t *area = hm_get(window->scenes, "AREA_HUD");
	sfText *x = hm_get(area->objs, "X");
	sfText *y = hm_get(area->objs, "Y");

	if (!x || !y)
		return (0);
	sfText_setString(x, my_strcat("X = ", int_to_str(AREA_COOR_X)));
	sfText_setString(y, my_strcat("Y = ", int_to_str(AREA_COOR_Y)));
}