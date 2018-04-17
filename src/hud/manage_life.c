/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** manage_life
*/

#include "rpg.h"

void manage_life(my_w_t *window)
{
	int ratios = PLAYER_CHARAC.health / PLAYER_CHARAC.max_health;
	scene_t *health = hm_get(window->scenes, "HEALTH_HUD");
	sfRectangleShape *rec = hm_get(health->objs, "HEALTH_BAR");
	sfIntRect rect = sfRectangleShape_getTextureRect(rec);

	rect.width *= ratios;
	if (rect.width < 0)
		rect.width = 0;
	sfRectangleShape_setTextureRect(rec, rect);
}