/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "rpg.h"

/*
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

void update_move_right(sfRectangleShape *notif, sfText *notif_text,
char *notif_output, int *offset)
{
	if (sfRectangleShape_getPosition(notif).x <= 390)
		*offset *= -1;
	else if (*offset == 0)
		*offset = -4;
	move_and_update(notif, notif_text, notif_output, *offset);
}

int manage_notif_right(game_t *game, char *notif_output)
{
	scene_t *battle_game = hm_get(game->scenes, "BATTLE");
	obj_t *obj = NULL;
	sfText *notif_text = NULL;
	sfRectangleShape *notif_bg = NULL;
	static int check_hit = 0;
	static int offset = -4;

	if (NOTIF_NULL_ARGS || (BATTLE_GAME_NULL_DATA))
		return (84);
	obj = hm_get(battle_game->objs, "NOTIF_RIGHT");
	notif_text = hm_get(battle_game->texts, "NOTIF_RIGHT");
	if (!obj || !notif_text || !(notif_bg = obj->obj) )
		return (84);
	if (IS_APRESSED || IS_A_BATTLE)
		return (0);
	if ((check_hit = 1) && sfRectangleShape_getPosition(notif_bg).x > 800)
		init_at_default(notif_bg, notif_text, &check_hit, &offset);
	update_move_right(notif_bg, notif_text, notif_output, &offset);
	return (0);
}*/