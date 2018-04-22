/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** manage_life
*/

#include "rpg.h"

int manage_life(game_t *game)
{
	float ratios;
	scene_t *health = hm_get(SCENES, "HEALTH_HUD");
	obj_t *obj = NULL;

	if (check_unexisting_scene((bucket_t *)health, "HEALTH_HUD") != 0)
		return (84);
	obj = hm_get(health->objs, "HEALTH_BAR");
	if (check_unexisting_obj((bucket_t *)obj,
	"HEALTH_BAR", "HEALTH_HUD") != 0)
		return (84);
	if (PLAYER_MAX_HP <= 0)
		return (0);
	ratios = (float)PLAYER_HEALTH /
		(float)PLAYER_MAX_HP * 100.0;
	obj->obj_rect.rect.width = MIN(ratios, 100);
	obj->obj_rect.rect.width = MAX(obj->obj_rect.rect.width, 0);
	sfRectangleShape_setTextureRect(obj->obj, obj->obj_rect.rect);
	sfRectangleShape_setSize(obj->obj,
	V2F(obj->obj_rect.rect.width, obj->obj_rect.rect.height));
	return (0);
}