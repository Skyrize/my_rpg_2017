/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** set_hud_opacity
*/

#include "rpg.h"

void set_hud_opacity(bucket_t *bucket, my_w_t *window)
{
	obj_t *obj = bucket->value;
	sfRectangleShape *rec;

	if (!obj)
		return;
	rec = obj->obj;
	if (!rec || !PLAYER.character)
		return;
	if (PLAYER.character->obj_rect.animated)
		sfRectangleShape_setFillColor(rec, TRANSPARENCY_COLOR);
	else
		sfRectangleShape_setFillColor(rec, REGULAR_COLOR);
}

int manage_hud_opacity(my_w_t *window)
{
	scene_t *health = hm_get(window->scenes, "HEALTH_HUD");
	scene_t *game_bar = hm_get(window->scenes, "GAME");

	if (!health || !game_bar)
		return (84);
	read_hashmap(window, health->objs, &set_hud_opacity);
	read_hashmap(window, game_bar->objs, &set_hud_opacity);
}