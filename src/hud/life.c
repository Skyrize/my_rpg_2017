/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** manage_life
*/

#include "rpg.h"

int manage_life(my_w_t *window)
{
	float ratios;
	scene_t *health = hm_get(SCENES, "HEALTH_HUD");
	obj_t *obj = hm_get(health->objs, "HEALTH_BAR");

	if (PLAYER_CHARAC.max_health <= 0)
		return (0);
	if (!obj || !health)
		return (84);
	ratios = (float)PLAYER_CHARAC.health /
		(float)PLAYER_CHARAC.max_health * 100.0;
	obj->obj_rect.rect.width = MIN(ratios, 100);
	obj->obj_rect.rect.width = MAX(obj->obj_rect.rect.width, 0);
	sfRectangleShape_setTextureRect(obj->obj, obj->obj_rect.rect);
	sfRectangleShape_setSize(obj->obj,
	V2F(obj->obj_rect.rect.width, obj->obj_rect.rect.height));
	return (0);
}