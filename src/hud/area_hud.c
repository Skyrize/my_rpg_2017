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
	sfText *pos_area = hm_get(area->texts, "POS");

	if (!pos_area)
		return (0);
	sfText_setString(pos_area, my_strcat(int_to_str(AREA_COOR_X),
				my_strcat(",", int_to_str(AREA_COOR_Y))));
	return (0);
}