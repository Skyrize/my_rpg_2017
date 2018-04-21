/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "rpg.h"

void init_at_default(sfRectangleShape *notif, sfText *notif_text,
int *check_hit, int *offset)
{
	sfRectangleShape_setPosition(notif, (sfVector2f){800, 10});
	sfText_setPosition(notif_text, (sfVector2f){840, 50});
	*check_hit = 0;
	*offset = 0;
}

void move_and_update(sfRectangleShape *notif, sfText *notif_text,
char *notif_output, int offset)
{
	sfText_setString(notif_text, notif_output);
	sfRectangleShape_move(notif, (sfVector2f){offset, 0});
	sfText_move(notif_text, (sfVector2f){offset, 0});
}

int manage_notif(window_t *window, char *notif_output)
{
	scene_t *battle_game = hm_get(SCENES, "BATTLE");
	obj_t *obj = hm_get(battle_game->objs, "NOTIF");
	sfText *notif_text = hm_get(battle_game->texts, "NOTIF_TEXT");
	sfRectangleShape *notif_bg = obj->obj;
	static int check_hit;
	static int offset = -2;

	if (!notif_bg || !notif_text ||
	(!sfMouse_isButtonPressed(sfMouseLeft) && check_hit == 0))
		return (0);
	check_hit = 1;
	if (sfRectangleShape_getPosition(notif_bg).x > 800)
		init_at_default(notif_bg, notif_text, &check_hit, &offset);
	move_and_update(notif_bg, notif_text, notif_output, offset);
	if (sfRectangleShape_getPosition(notif_bg).x <= 400) {
		offset *= -1;
	} else if (offset == 0)
		offset = -2;
	return (0);
}