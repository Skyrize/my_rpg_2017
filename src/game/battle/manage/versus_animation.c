/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "my.h"
#include "rpg.h"

int update_alpha_icon(sfRectangleShape *rec)
{
	static int offset = 0;

	if (!rec)
		return (84);
	if (offset < 255)
		offset += 1;
	else if (offset < 1)
		offset = 0;
	sfRectangleShape_setFillColor(rec, (sfColor){255, 255, 255, offset});
	return (0);
}

int manage_versus_animation(game_t *game)
{
	scene_t *battle_game = hm_get(SCENES, "BATTLE");
	sfRectangleShape *versus_icon = NULL;

	if (!battle_game || !game)
		return (84);
	versus_icon = hm_get(battle_game->objs, "VERSUS_ICO");
	if (!versus_icon)
		return (84);
	if (update_alpha_icon(versus_icon) != 0)
		return (84);
	return (0);
}