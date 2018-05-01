/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** manage_life
*/

#include "rpg.h"

int manage_life_in_game(game_t *game)
{
	float ratios;
	scene_t *health_hud = hm_get(SCENES, "HEALTH_HUD");
	obj_t *obj = NULL;

	if (check_unexisting_scene((bucket_t *)health_hud, "HEALTH_HUD") != 0)
		return (84);
	obj = hm_get(health_hud->objs, "HEALTH_BAR");
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

int manage_life_in_battle(game_t *game)
{
	float ratios;
	scene_t *health_hud = hm_get(SCENES, "BATTLE");
	obj_t *obj = NULL;

	if (check_unexisting_scene((bucket_t *)health_hud, "BATTLE") != 0)
		return (84);
	obj = hm_get(health_hud->objs, "HEALTH_BAR");
	if (check_unexisting_obj((bucket_t *)obj,
	"HEALTH_BAR", "BATTLE") != 0)
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

int manage_life(game_t *game)
{
	if (!my_strcmp(CURRENT_BUCKET->key, "BATTLE")) {
		if (manage_life_in_battle(game) == 84)
			return (84);
	} else {
		if (manage_life_in_game(game) == 84)
			return (84);
	}
	return (0);
}