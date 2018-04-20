/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** set_hud_opacity
*/

#include "rpg.h"

void increment_opacity(sfRectangleShape *rec, int ratio)
{
	sfColor color = sfRectangleShape_getFillColor(rec);

	if ((ratio == -1 && color.a > 50) || (ratio == 1 && color.a < 255))
		color.a += (5 * ratio);
	sfRectangleShape_setFillColor(rec, color);
}

int set_hud_opacity(bucket_t *bucket, my_w_t *window)
{
	obj_t *obj = bucket->value;
	sfRectangleShape *rec;

	if (!obj)
		return (1);
	rec = obj->obj;
	if (!rec)
		return (1);
	if (window->game.movement.is_moving)
		increment_opacity(rec, -1);
	else
		increment_opacity(rec, 1);
	return (0);
}

int manage_hud_opacity(my_w_t *window)
{
	scene_t *health = hm_get(SCENES, "HEALTH_HUD");
	scene_t *game_bar = hm_get(SCENES, "GAME");

	if (!health || !game_bar)
		return (84);
	read_hashmap(window, game_bar->objs, &set_hud_opacity);
	read_hashmap(window, health->objs, &set_hud_opacity);
	return (0);
}