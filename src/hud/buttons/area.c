/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** area_hud
*/

#include "rpg.h"

int change_area_hud(game_t *game)
{
	scene_t *area = hm_get(SCENES, "AREA_HUD");
	sfText *pos_area;

	if (check_unexisting_scene((bucket_t *)area, "AREA_HUD") != 0)
		return (84);
	pos_area = hm_get(area->texts, "POS");
	if (check_unexisting_text((bucket_t *)pos_area, "POS", "AREA_HUD") != 0)
		return (84);
	sfText_setString(pos_area, my_strcat(int_to_str(AREA_COOR_X),
				my_strcat(",", int_to_str(AREA_COOR_Y))));
	return (0);
}