/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "rpg.h"

void init_at_default_left(sfRectangleShape *notif, sfText *notif_text,
int *check_hit, int *offset)
{
	sfRectangleShape_setPosition(notif, (sfVector2f){-400, 10});
	sfText_setPosition(notif_text, (sfVector2f){-360, 50});
	*check_hit = 0;
	*offset = 0;
}

void update_offset(int *offset, sfRectangleShape *notif_bg)
{
	if (sfRectangleShape_getPosition(notif_bg).x <= 3 && *offset != -2) {
		*offset = 2;
	} else if (offset == 0)
		*offset *= -1;
}

int manage_notif_left(game_t *window, char *notif_output)
{
	scene_t *battle_game = hm_get(window->scenes, "BATTLE");
	obj_t *obj = hm_get(battle_game->objs, "NOTIF_LEFT");
	sfText *notif_text = hm_get(battle_game->texts, "NOTIF_LEFT");
	sfRectangleShape *notif_bg = obj->obj;
	static int check_hit;
	static int offset = 2;

	if (!notif_bg || !notif_text ||
	(!sfMouse_isButtonPressed(sfMouseLeft) && check_hit == 0))
		return (0);
	check_hit = 1;
	if (sfRectangleShape_getPosition(notif_bg).x > 3)
		offset = -2;
	if (sfRectangleShape_getPosition(notif_bg).x < -400)
		init_at_default_left(notif_bg, notif_text, &check_hit, &offset);
	move_and_update(notif_bg, notif_text, notif_output, offset);
	update_offset(&offset, notif_bg);
	return (0);
}